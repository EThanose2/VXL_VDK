#include "main.h"
#include "timer.h"
#include "led_display.h"

extern int mode;
extern int timer1;
extern int timer2;
extern int red;
extern int green;
extern int amber;

extern int led_scan_counter, led_scan_flag;
extern int sec_counter, sec_flag;
extern int blink_counter, blink_flag;

extern int index_led;

typedef enum {
    INIT = 0,
    TRAFFIC_GREEN_RED,
    TRAFFIC_AMBER_RED,
    TRAFFIC_RED_GREEN,
    TRAFFIC_RED_AMBER
} TrafficState_t;

TrafficState_t traffic_status = INIT;

void traffic_light_run(void) {
	updateLedBuffer();

	if (led_scan_flag == 1) {
		led_scan_flag = 0;
		update7SEG(index_led++);
		index_led = index_led % 4;
	}

	if (mode == 1) {
		if (sec_flag == 1) {
			sec_flag = 0;
			timer1--;
			timer2--;
		}

		switch (traffic_status) {
			case INIT:
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|GREEN1_Pin|AMBER1_Pin|
										 RED2_Pin|GREEN2_Pin|AMBER2_Pin, 0);
				traffic_status = TRAFFIC_GREEN_RED;
				timer1 = green;
				timer2 = red;
				break;

			case TRAFFIC_GREEN_RED:
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|AMBER2_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, GREEN1_Pin|RED2_Pin, 1);

				if (timer1 <= 0) {
					traffic_status = TRAFFIC_AMBER_RED;
					timer1 = amber;
				}
				break;

			case TRAFFIC_AMBER_RED:
				HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, AMBER1_Pin, 1);

				if (timer1 <= 0) {
					traffic_status = TRAFFIC_RED_GREEN;
					timer1 = red;
					timer2 = green;
				}
				break;

			case TRAFFIC_RED_GREEN:
				HAL_GPIO_WritePin(GPIOA, AMBER1_Pin|RED2_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|GREEN2_Pin, 1);

				if (timer2 <= 0) {
					traffic_status = TRAFFIC_RED_AMBER;
					timer2 = amber;
				}
				break;

			case TRAFFIC_RED_AMBER:
				HAL_GPIO_WritePin(GPIOA, GREEN2_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, AMBER2_Pin, 1);

				if (timer2 <= 0) {
					traffic_status = TRAFFIC_GREEN_RED;
					timer1 = green;
					timer2 = red;
				}
				break;

			default:
				traffic_status = INIT;
				break;
		}
	}
	else {
		traffic_status = INIT;

		switch (mode) {
			case 2:
				if (blink_flag) HAL_GPIO_WritePin(GPIOA, RED1_Pin|RED2_Pin, GPIO_PIN_SET);
				else HAL_GPIO_WritePin(GPIOA, RED1_Pin|RED2_Pin, GPIO_PIN_RESET);

				HAL_GPIO_WritePin(GPIOA, GREEN1_Pin|AMBER1_Pin|GREEN2_Pin|AMBER2_Pin, GPIO_PIN_RESET);
				break;

			case 3:
				if (blink_flag) HAL_GPIO_WritePin(GPIOA, AMBER1_Pin|AMBER2_Pin, GPIO_PIN_SET);
				else HAL_GPIO_WritePin(GPIOA, AMBER1_Pin|AMBER2_Pin, GPIO_PIN_RESET);

				HAL_GPIO_WritePin(GPIOA, GREEN1_Pin|RED1_Pin|GREEN2_Pin|RED2_Pin, GPIO_PIN_RESET);
				break;

			case 4:
				if (blink_flag) HAL_GPIO_WritePin(GPIOA, GREEN1_Pin|GREEN2_Pin, GPIO_PIN_SET);
				else HAL_GPIO_WritePin(GPIOA, GREEN1_Pin|GREEN2_Pin, GPIO_PIN_RESET);

				HAL_GPIO_WritePin(GPIOA, RED1_Pin|AMBER1_Pin|RED2_Pin|AMBER2_Pin, GPIO_PIN_RESET);
				break;

			default: break;
		}
	}
}

