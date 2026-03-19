#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

#include "main.h"

/* -------------------------------------------------------------------------- */
/*                          FUNCTION PROTOTYPES                               */
/* -------------------------------------------------------------------------- */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif // INTERRUPT_HANDLER_H