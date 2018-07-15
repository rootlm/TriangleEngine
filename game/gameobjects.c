#include "../globaldef.h"
#include "../object.h"
#include "gameobjects.h"
#include "objectdef.h"

//include files with object functions here

void Object_AddType(void(*createfunc)(unsigned short),void(*stepfunc)(unsigned short),void(*drawfunc)(unsigned short),unsigned short type) {

}

void Object_Init() {
	Object_InitArray();
}