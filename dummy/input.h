#include "../globaldef.h"
#ifndef __INPUT__
#define __INPUT__

typedef struct {
	unsigned char previous;
	unsigned char current;
} keystate_t;

keystate_t* globalkeys;

#define KEYBOARDSIZE 256

void Input_Init();
bool keyboard_check(char statetocheck);
bool keyboard_check_pressed(char statetocheck);
bool keyboard_check_released(char statetocheck);
void Input_Update();
void Input_Close();
#endif
