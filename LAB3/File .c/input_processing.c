#include "main.h"
#include "input_reading.h"

extern int red;
extern int green;
extern int amber;
extern int mode;

int editing_time = 0;

void fsm_for_input_processing(void){
	// Xử lí nút 1
	if (is_button_pressed(0)) {
		mode++;
		if (mode > 4) mode = 1;

		if (mode == 2) editing_time = red;
		else if (mode == 3) editing_time = amber;
		else if (mode == 4) editing_time = green;
	}

	// Xử lí nút 2
	if (is_button_pressed(1)) {
		if (mode > 1) {
			editing_time++;
			if (editing_time > 99) editing_time = 1;
		}
	}

	// Xử lí nút 3
	if (is_button_pressed(2)) {
		if (mode == 2) {
			red = editing_time;
			green = red - amber;
		}
		else if (mode == 3) {
			amber = editing_time;
			red = amber + green;
		}
		else if (mode == 4) {
			green = editing_time;
			red = green + amber;
		}
	}
}
