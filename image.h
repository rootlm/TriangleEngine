#include "render.h"

#ifndef __IMAGE__
#define __IMAGE__

	typedef struct {
		Engine_Texture* data;
		unsigned short timeout;
		char* name;
	} image_t;

	image_t* images;
	unsigned short numimages;

	void Image_Init();

	void Image_Close();

	unsigned short Image_Get(const char*filename);
#endif