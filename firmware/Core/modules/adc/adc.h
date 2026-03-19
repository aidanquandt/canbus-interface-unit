#ifndef ADC_H
#define ADC_H

#include "main.h"
#include "common_defs.h"

/* -------------------------------------------------------------------------- */
/*                                DEFINITIONS                                 */
/* -------------------------------------------------------------------------- */

#define ADC_BUFFER_SIZE NUM_ANALOG_SENSORCHANNELS

/* -------------------------------------------------------------------------- */
/*                                 TYPEDEFS                                   */
/* -------------------------------------------------------------------------- */

typedef enum
{
    ADC_CONV_INCOMPLETE = 0U,
    ADC_CONV_COMPLETE
} ADCConvStatus_E;

/* -------------------------------------------------------------------------- */
/*                              EXTERNAL VARIABLES                            */
/* -------------------------------------------------------------------------- */

extern ADC_HandleTypeDef hadc1;

/* -------------------------------------------------------------------------- */
/*                          FUNCTION PROTOTYPES                               */
/* -------------------------------------------------------------------------- */

void adc_start_dma();
void adc_updateSensorData(SensorData_S *SensorData);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);

#endif // ADC_H