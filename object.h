#include "globaldef.h"

#ifndef __OBJECT__
#define __OBJECT__

	#define MAXOBJECTS 512

	#define FLAGTYPE unsigned char //which type of value flags are)

	typedef struct {
		unsigned short type;
		FLAGTYPE flags;
		float x;
		float y;
		float xspeed;
		float yspeed;
		signed char depth;
		unsigned short sprite;
		float frame;
		float framespeed;
		unsigned char state;
		unsigned short hp;
		unsigned short timer;
	} obj_example;

	obj_example** objects;
	unsigned short numobjects;

	unsigned short* draworder;

#endif