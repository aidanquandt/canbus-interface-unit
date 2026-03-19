#ifndef CANBUS_H
#define CANBUS_H

#include "main.h"
#include "common_defs.h"

/* -------------------------------------------------------------------------- */
/*                                DEFINITIONS                                 */
/* -------------------------------------------------------------------------- */

#define NUM_BYTES_PER_CAN_FRAME 8U

/* -------------------------------------------------------------------------- */
/*                              EXTERNAL VARIABLES                            */
/* -------------------------------------------------------------------------- */

extern CAN_HandleTypeDef hcan1;

/* -------------------------------------------------------------------------- */
/*                                 TYPEDEFS                                   */
/* -------------------------------------------------------------------------- */

typedef enum
{
#if (DEBUG_MODE)
    CAN_FRAME_0_ID = 0x342,
    CAN_FRAME_1_ID = 0x101,
#elif (HARDWARE_CIU_1)
    CAN_FRAME_0_ID = 0x100,
    CAN_FRAME_1_ID = 0x101,
#else
    CAN_FRAME_0_ID = 0x102,
    CAN_FRAME_1_ID = 0x103,
#endif // DEBUG_MODE
} CANID_E;

typedef enum
{
    CAN_FRAME_0 = 0U,
    CAN_FRAME_1,
    NUM_CAN_FRAMES
} CANFrame_E;

typedef enum
{
    CAN_FRAME_BYTE0 = 0U,
    CAN_FRAME_BYTE1,
    CAN_FRAME_BYTE2,
    CAN_FRAME_BYTE3,
    CAN_FRAME_BYTE4,
    CAN_FRAME_BYTE5,
    CAN_FRAME_BYTE6,
    CAN_FRAME_BYTE7,
    NUM_CAN_FRAME_BYTES
} CANFrameByte_E;

typedef struct
{
    CAN_TxHeaderTypeDef TxHeader;
    CAN_HandleTypeDef *hcan;
    uint32_t TxMailbox;
    uint8_t CANDataBuffer[NUM_CAN_FRAMES][NUM_SENSORCHANNELS];
} CANTransmitData_S;

typedef struct
{
    CAN_RxHeaderTypeDef RxHeader;
    CAN_HandleTypeDef *hcan;
} CANReceiveData_S;

/* -------------------------------------------------------------------------- */
/*                          FUNCTION PROTOTYPES                               */
/* -------------------------------------------------------------------------- */

void canBus_init();
void canBus_transmitSensorData(SensorData_S *SensorData);

#endif // CANBUS_H