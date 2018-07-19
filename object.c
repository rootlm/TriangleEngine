#include "globaldef.h"
#include "object.h"

void Object_InitArray() {
	objects = calloc(MAXOBJECTS,sizeof(void*));
}

unsigned short Object_Create(float x,float y,unsigned short type) {
	if (numobjects < MAXOBJECTS) {
		if (objfuncs[type].createfunc != NULL) {
			objfuncs[type].createfunc(numobjects);
			objects[numobjects]->x = x;
			objects[numobjects]->y = y;
			objects[numobjects]->type = type;
			unsigned short numobjprev = numobjects;
			numobjects++;
			return numobjects;
		}
	}
	else {
		return ERROR_NO_OBJ;
	}
}

void Objects_Update() {
	signed short i=0;
	while (i < numobjects) {
		if (objects[i] == NULL) {
			return;
		}
		else if (objfuncs[objects[i]->type].stepfunc != NULL && !objects[i]->delete) {
			objfuncs[objects[i]->type].stepfunc(i);
		}
		if (objects[i]->delete) {
			objects[i]->delete=false;
			Object_Delete(i);
			i--;
		}
	i++;
	}
}

void Objects_Draw() {
	signed short i=0;
	while (i < numobjects) {
		if (objects[i] == NULL) {
			return;
		}
		else if (objfuncs[objects[i]->type].drawfunc != NULL && !objects[i]->delete) {
			objfuncs[objects[i]->type].drawfunc(i);
		}
	i++;
	}
}

void Object_Delete(unsigned short id) {
	if (objects[id] != NULL) {
		free(objects[id]);
		//memmove(&objects[id], &objects[id] + sizeof(char*), sizeof(char*)*((MAXOBJECTS-1) - id));
		memmove(&objects[id], &objects[id+1], sizeof(char*)*((MAXOBJECTS-1) - id));
		numobjects--;
		objects[MAXOBJECTS-1]=NULL;
	}
}

void Object_MarkForDeletion(unsigned short id) {
	if (objects[id] != NULL) {
		objects[id]->delete=true;
	}
}

void Object_DeleteAll() {
	unsigned short tempnumobjects=numobjects;
	unsigned short i=0;
	while (i < tempnumobjects) {
		Object_Delete(0);
	i++;
	}
	numobjects=0;
}
