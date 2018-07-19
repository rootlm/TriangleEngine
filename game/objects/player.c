#include "../../globaldef.h"
#include "../../sprite.h"
#include "../../object.h"
#include "render.h"
#include "player.h"
#include "../../math2.h"

void obj_player_create(unsigned short id) {
	objects[id] = calloc(1,sizeof(obj_player_t));
	objects[id]->sprite = Sprite_Get("SPR_PLAYER");
	objects[id]->yspeed = rand() % 360;
}
void obj_player_step(unsigned short id) {
	//objects[id]->x = rand() % 320;
	//objects[id]->y = rand() % 240;
	objects[id]->x += 2;
	objects[id]->y = objects[id]->yspeed+(dsin(objects[id]->x)*8);
	if (objects[id]->x > 512) {
		Object_DeleteSelf();
		return;
	}
	//objects[id]->x = 64;
	//objects[id]->y = 128;

}
void obj_player_draw(unsigned short id) {
	draw_sprite(objects[id]->sprite,0,objects[id]->x,objects[id]->y);
	//draw_sprite_ext(objects[id]->sprite,0,objects[id]->x,objects[id]->y,(rand() % 8),(rand() % 4),(rand() % 360));
	//draw_sprite_ext(objects[id]->sprite,0,0,160,(rand() % 8),(rand() % 4),(rand() % 360));
}