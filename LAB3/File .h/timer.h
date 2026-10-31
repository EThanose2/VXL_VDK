#ifndef INC_TIMER_H_
#define INC_TIMER_H_

void timer_run();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_TIMER_H_ */
