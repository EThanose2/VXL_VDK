#include "main.h"

#define NO_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

// Biến cờ đánh dấu sự kiện bấm mới
static uint8_t flagForButtonPress[NO_OF_BUTTONS];

// Hàm đọc trạng thái nút nhấn
GPIO_PinState get_button_pin(uint8_t index) {
    switch(index) {
        case 0: return HAL_GPIO_ReadPin(GPIOA, BUTTON1_Pin);
        case 1: return HAL_GPIO_ReadPin(GPIOA, BUTTON2_Pin);
        case 2: return HAL_GPIO_ReadPin(GPIOA, BUTTON3_Pin);
        default: return BUTTON_IS_RELEASED;
    }
}

void button_reading(void){
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = get_button_pin(i);;

		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
			if (buttonBuffer[i] == BUTTON_IS_RELEASED && debounceButtonBuffer1[i] == BUTTON_IS_PRESSED) {
				flagForButtonPress[i] = 1;
			}
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}
	}
}

unsigned char is_button_pressed(uint8_t index){
	if (index >= NO_OF_BUTTONS) return 0;
	if (flagForButtonPress[index] == 1) {
		flagForButtonPress[index] = 0;
		return 1;
	}
	return 0;
}


