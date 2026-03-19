#include "canBus.h"

/* -------------------------------------------------------------------------- */
/*                              PRIVATE DATA DECLARATIONS                     */
/* -------------------------------------------------------------------------- */
static CANTransmitData_S txData = {
    .TxHeader = {0},
    .TxMailbox = 0,
    .CANDataBuffer = {{0}},
    .hcan = &hcan1,
};

static uint32_t CANFrameIDs[NUM_CAN_FRAMES] = {
    [CAN_FRAME_0] = CAN_FRAME_0_ID,
    [CAN_FRAME_1] = CAN_FRAME_1_ID
};

/* -------------------------------------------------------------------------- */
/*                              PRIVATE FUNCTIONS                             */
/* -------------------------------------------------------------------------- */
static void canBus_copySensorDataToBuffers(SensorData_S *SensorData)
{
    /* Four 16-bit words per frame: frame0 = analog ch0–3; frame1 = analog ch4–5 + both wheel speeds. */
    uint16_t const frameWords[NUM_CAN_FRAMES][4] = {
        {
            SensorData->AnalogSensorData[ANALOG_CH0],
            SensorData->AnalogSensorData[ANALOG_CH1],
            SensorData->AnalogSensorData[ANALOG_CH2],
            SensorData->AnalogSensorData[ANALOG_CH3],
        },
        {
            SensorData->AnalogSensorData[ANALOG_CH4],
            SensorData->AnalogSensorData[ANALOG_CH5],
            SensorData->SpeedSensorData[SPEED_CH6],
            SensorData->SpeedSensorData[SPEED_CH7],
        },
    };

    for (CANFrame_E CANFrameNum = CAN_FRAME_0; CANFrameNum < NUM_CAN_FRAMES; CANFrameNum++)
    {
        for (CANFrameByte_E CANFrameByteNum = CAN_FRAME_BYTE0; CANFrameByteNum < NUM_CAN_FRAME_BYTES;
             CANFrameByteNum++)
        {
            uint16_t const word = frameWords[CANFrameNum][CANFrameByteNum / 2U];
            if (CANFrameByteNum % 2U == 0U)
            {
                txData.CANDataBuffer[CANFrameNum][CANFrameByteNum] = (uint8_t)((word >> 8U) & 0xFFU);
            }
            else
            {
                txData.CANDataBuffer[CANFrameNum][CANFrameByteNum] = (uint8_t)(word & 0xFFU);
            }
        }
    }
}

static void canBus_transmitBuffers()
{
    for (CANFrame_E CANFrameNum = CAN_FRAME_0; CANFrameNum < NUM_CAN_FRAMES; CANFrameNum++)
    {
        txData.TxHeader.StdId = CANFrameIDs[CANFrameNum];

        while (HAL_CAN_IsTxMessagePending(txData.hcan, txData.TxMailbox))
        {
            // Wait for buffer to clear
        }

        if (HAL_CAN_AddTxMessage(txData.hcan, &txData.TxHeader, txData.CANDataBuffer[CANFrameNum], &txData.TxMailbox) != HAL_OK)
        {
            HAL_GPIO_WritePin(STATUS_LED_GPIO_PORT, STATUS_LED_PIN, GPIO_PIN_SET);
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */
void canBus_init()
{
    txData.TxHeader.ExtId = 0x00;
    txData.TxHeader.IDE = CAN_ID_STD;
    txData.TxHeader.RTR = CAN_RTR_DATA;
    txData.TxHeader.DLC = NUM_CAN_FRAME_BYTES;
    txData.TxHeader.TransmitGlobalTime = DISABLE;
}

void canBus_transmitSensorData(SensorData_S *SensorData)
{
    canBus_copySensorDataToBuffers(SensorData);
    canBus_transmitBuffers();
}