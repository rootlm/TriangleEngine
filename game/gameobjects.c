#include "../globaldef.h"
#include "../object.h"
#include "gameobjects.h"
#include "objectdef.h" //<-- this will include the objects h's too so NO HAVING 2 OF THE SAME INCLUDE LIST

//include files with object functions here

void Object_AddType(void(*createfunc)(unsigned short),void(*stepfunc)(unsigned short),void(*drawfunc)(unsigned short),unsigned short type) {
	objfuncs[type].createfunc = createfunc;
	objfuncs[type].stepfunc = stepfunc;
	objfuncs[type].drawfunc = drawfunc;
}


void Object_Init() {
	objfuncs = (objfuncs_t*)malloc(sizeof(objfuncs_t)*NUMOBJECTTYPES); //w/e
	Object_InitArray();

	//add objects here!
	Object_AddType(obj_player_create,obj_player_step,obj_player_draw,OBJ_PLAYER);
}

void Object_Close() {
	Object_DeleteAll();
	free (objects);
	free(objfuncs);
}