#include "main.h"
#include "input_reading.h"
#include "led_display.h"

int led_scan_counter = 0, led_scan_flag = 0;
int sec_counter = 0, sec_flag = 0;
int blink_counter = 0, blink_flag = 0;

void timer_run() {
	led_scan_counter++;
	if (led_scan_counter >= 5) {
		led_scan_counter = 0;
		led_scan_flag = 1;
	}

	sec_counter++;
	if (sec_counter >= 100) {
		sec_counter = 0;
		sec_flag = 1;
	}

	blink_counter++;
	if (blink_counter >= 25) {
		blink_counter = 0;
		blink_flag = 1 - blink_flag;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		button_reading();
		timer_run();
	}
}

