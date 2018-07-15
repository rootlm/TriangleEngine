#include "render.h"

#ifndef __SPRITE__
#define __SPRITE__
	typedef struct {
		Renderer_Rect framerect;
		unsigned char animlength;
		unsigned char* anim; //array the size of animlength, each frame is a number of how many sprite widths past the framerect
		//if animlength is 0 don't allocate anim i guess, and i'll have drawing functions take that into account..
		unsigned short xoff; //offset
		unsigned short yoff;
	} spritedata_t;

	typedef struct {
		spritedata_t data;
		char* name;
		char* sheetname;
		unsigned short sheet;
	} sprite_t;

	sprite_t* sprites;
	unsigned short numsprites;

	void Sprite_Init();

	void Sprite_Close();

	spritedata_t Sprite_Load(const char* filename,char** sheetnameloc);

	unsigned short Sprite_Get(const char*filename);
#endif