#include "../../globaldef.h"
#include "../../sprite.h"
#include "../../object.h"
#include "render.h"
#include "player.h"

void obj_player_create(unsigned short id) {
	objects[id] = calloc(1,sizeof(obj_player_t));
	objects[id]->sprite = Sprite_Get("SPR_PLAYER");
}
void obj_player_step(unsigned short id) {
	objects[id]->x = rand() % 320;
	objects[id]->y = rand() % 240;
}
void obj_player_draw(unsigned short id) {
	draw_sprite(objects[id]->sprite,0,objects[id]->x,objects[id]->y);
}