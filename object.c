#include "globaldef.h"
#include "object.h"

void Object_InitArray() {
	objects = calloc(MAXOBJECTS,sizeof(void*));
}

unsigned short Object_Create(unsigned short type,float x,float y) {
	unsigned short i = 0;
	while (objects[i] != NULL && i < MAXOBJECTS) {		
	i++;
	}
	if (i < MAXOBJECTS) {
		//call function here
		objects[i]->x = x;
		objects[i]->y = y;
		objects[i]->type = type;
		numobjects++;
	}
	else {
		i=65535;
	}
return i;
}


