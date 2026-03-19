#include "interruptHandler.h"

/* -------------------------------------------------------------------------- */
/*                              PRIVATE DATA DECLARATIONS                     */
/* -------------------------------------------------------------------------- */

#if (DEBUG_MODE)
static SensorData_S DebugSensorData = {
    .AnalogSensorData = {0U, 0U, 0U, 0U, 0U, 0U},
    .SpeedSensorData = {0U, 0U}
};
#endif // DEBUG_MODE

// Speedsensor channels are volatile to allow for software interrupts to increment them
static SensorData_S SensorData = {0};
static volatile uint16_t SpeedCounter[NUM_SPEED_SENSORCHANNELS];

/* -------------------------------------------------------------------------- */
/*                          INTERRUPT CALLBACKS                               */
/* -------------------------------------------------------------------------- */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3)
    {
#if (DEBUG_MODE)
        // Use debug sensor data in debug mode
        SensorData = DebugSensorData;
#else
        // Update sensor data from ADC in normal mode
        adc_updateSensorData(&SensorData);
#endif // DEBUG_MODE

        // Update speed sensor data from the speed counters
        for (SpeedSensorChannel_E SpeedChannel = SPEED_CH6; SpeedChannel < NUM_SPEED_SENSORCHANNELS; SpeedChannel++)
        {
            SensorData.SpeedSensorData[SpeedChannel] = SpeedCounter[SpeedChannel];
            SpeedCounter[SpeedChannel] = 0U; // Reset the speed counter after reading
        }

        canBus_transmitSensorData(&SensorData);
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == CH6_SPEED_PIN)
    {
        SpeedCounter[SPEED_CH6] += 1U;
    }
    else if (GPIO_Pin == CH7_SPEED_PIN)
    {
        SpeedCounter[SPEED_CH7] += 1U;
    }
}