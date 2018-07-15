#include "../globaldef.h"
#include "input.h"

void Input_Init() {
	globalkeys = calloc(KEYBOARDSIZE,sizeof(keystate_t));
}

bool keyboard_check(char statetocheck) {
	if (globalkeys[statetocheck].current) {
		return 1;
	}
	else {
		return 0;
	}

}

bool keyboard_check_pressed(char statetocheck) {
	if (globalkeys[statetocheck].current && !globalkeys[statetocheck].previous) {
		return 1;
	}
else {
	return 0;
}

}

bool keyboard_check_released(char statetocheck) {
	if (!globalkeys[statetocheck].current && globalkeys[statetocheck].previous) {
		return 1;
	}
	else {
		return 0;
	}

}

void Input_Update() {

}

void Input_Close() {
	if (globalkeys != NULL) {
		free(globalkeys);
	}
}