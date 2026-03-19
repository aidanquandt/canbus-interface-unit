#include "adc.h"

/* -------------------------------------------------------------------------- */
/*                              PRIVATE DATA DECLARATIONS                     */
/* -------------------------------------------------------------------------- */

static volatile uint16_t adcBuffer[ADC_BUFFER_SIZE];
static volatile ADCConvStatus_E ADCConvCplt = ADC_CONV_INCOMPLETE;

/* -------------------------------------------------------------------------- */
/*                              PRIVATE FUNCTIONS                             */
/* -------------------------------------------------------------------------- */

static void adc_set_ADCConvCplt(ADCConvStatus_E AdcConvCpltStatus)
{
    ADCConvCplt = AdcConvCpltStatus;
}

static ADCConvStatus_E adc_get_ADCConvCplt()
{
    return ADCConvCplt;
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void adc_start_dma()
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adcBuffer, ADC_BUFFER_SIZE);
}

void adc_updateSensorData(SensorData_S *SensorData)
{
    // Set request flag and start DMA
    ADCConvCplt = false;
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adcBuffer, ADC_BUFFER_SIZE);

    while (adc_get_ADCConvCplt() == ADC_CONV_INCOMPLETE)
    {
        // Wait for ADC conversion to complete
    }

    for (AnalogSensorChannel_E SensorChannel = ANALOG_CH0; SensorChannel < NUM_ANALOG_SENSORCHANNELS; SensorChannel++)
    {
        SensorData->AnalogSensorData[SensorChannel] = (uint16_t)adcBuffer[SensorChannel];
    }

    return;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc == &hadc1)
    {
        adc_set_ADCConvCplt(ADC_CONV_COMPLETE);
    }
}