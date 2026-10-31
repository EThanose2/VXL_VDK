#include "main.h"

void display7SEG(int num) {
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
			break;

		case 1:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
			break;

		case 2:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
			break;

		case 3:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
			break;

		case 4:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
			break;

		case 5:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
			break;

		case 6:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
			break;

		case 7:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
			break;

		case 8:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
			break;

		case 9:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 0);
			break;

		default: break;
	}
}

int index_led;
int led_buffer[4] = {0, 0, 0, 0};
void update7SEG(int index) {
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, EN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, EN0_Pin, 0);
			display7SEG(led_buffer[0]);
			break;

		case 1:
			HAL_GPIO_WritePin(GPIOB, EN0_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, EN1_Pin, 0);
			display7SEG(led_buffer[1]);
			break;

		case 2:
			HAL_GPIO_WritePin(GPIOB, EN1_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, EN2_Pin, 0);
			display7SEG(led_buffer[2]);
			break;

		case 3:
			HAL_GPIO_WritePin(GPIOB, EN2_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, EN3_Pin, 0);
			display7SEG(led_buffer[3]);
			break;

		default: break;
	}
}

extern int mode;
extern int timer1;
extern int timer2;
extern int editing_time;
void updateLedBuffer() {
    if (mode == 1) {
        led_buffer[0] = timer1 / 10;
        led_buffer[1] = timer1 % 10;
        led_buffer[2] = timer2 / 10;
        led_buffer[3] = timer2 % 10;
    }
    else {
        led_buffer[0] = editing_time / 10;
        led_buffer[1] = editing_time % 10;
        led_buffer[2] = 0;
        led_buffer[3] = mode;
    }
}
