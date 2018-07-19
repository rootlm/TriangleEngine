#include "globaldef.h"

#ifndef __OBJECT__
#define __OBJECT__

	#define MAXOBJECTS 512

	#define ERROR_NO_OBJ 65535

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
		bool delete; //mark for deletion in the update loop
	} obj_example_t;

	obj_example_t** objects;
	unsigned short numobjects;

	unsigned short* draworder;

	typedef struct {
		void(*createfunc)(unsigned short);
		void(*stepfunc)(unsigned short);
		void(*drawfunc)(unsigned short);
	} objfuncs_t;


	objfuncs_t* objfuncs;

	void Object_InitArray();

	unsigned short Object_Create(float x,float y,unsigned short type);

	void Objects_Update();

	void Objects_Draw();

	void Object_Delete(unsigned short id);

	void Object_MarkForDeletion(unsigned short id);
	
	#define Object_DeleteSelf() Object_MarkForDeletion(id); return;

	void Object_DeleteAll();


#endif