#ifndef COMMON_H
#define COMMON_H

#include "main.h"

/* -------------------------------------------------------------------------- */
/*                                DEFINITIONS                                 */
/* -------------------------------------------------------------------------- */

// Set preprocessor here to determine which CIU is being used
#define HARDWARE_CIU_1 true
#define HARDWARE_CIU_2 false

#define DEBUG_MODE false

/* -------------------------------------------------------------------------- */
/*                                 TYPEDEFS                                   */
/* -------------------------------------------------------------------------- */

typedef enum
{
    SENSOR_CH0 = 0U,
    SENSOR_CH1,
    SENSOR_CH2,
    SENSOR_CH3,
    SENSOR_CH4,
    SENSOR_CH5,
    SENSOR_CH6,
    SENSOR_CH7,
    NUM_SENSORCHANNELS
} SensorChannel_E;

typedef enum
{
    ANALOG_CH0 = 0U,
    ANALOG_CH1,
    ANALOG_CH2,
    ANALOG_CH3,
    ANALOG_CH4,
    ANALOG_CH5,
    NUM_ANALOG_SENSORCHANNELS
} AnalogSensorChannel_E;

typedef enum
{
    SPEED_CH6 = 0U,
    SPEED_CH7,
    NUM_SPEED_SENSORCHANNELS
} SpeedSensorChannel_E;

typedef struct
{
    uint16_t AnalogSensorData[NUM_ANALOG_SENSORCHANNELS];
    volatile uint16_t SpeedSensorData[NUM_SPEED_SENSORCHANNELS];
} SensorData_S;

#endif // COMMON_H