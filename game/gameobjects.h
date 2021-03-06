#include "../globaldef.h"
#include "../object.h"
#include "objectdef.h"

#ifndef __GAMEOBJECTS__
#define __GAMEOBJECTS__

#define NUMOBJECTTYPES 512

void Object_AddType(void(*createfunc)(unsigned short),void(*stepfunc)(unsigned short),void(*drawfunc)(unsigned short),unsigned short type);

void Object_Init();

void Object_Close();

#endif