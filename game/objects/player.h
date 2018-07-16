#include "../../globaldef.h"
#include "../../sprite.h"
#include "../../object.h"
#include "render.h"

#ifndef __OBJS_PLAYER__
#define __OBJS_PLAYER__
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
	} obj_player_t;

	void obj_player_create(unsigned short id);
	void obj_player_step(unsigned short id);
	void obj_player_draw(unsigned short id);
#endif