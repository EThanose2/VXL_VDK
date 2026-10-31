#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

GPIO_PinState get_button_pin(uint8_t index);
void button_reading(void);
unsigned char is_button_pressed (uint8_t index);

#endif /* INC_INPUT_READING_H_ */
