#include "globaldef.h"
#include "render.h"
#include "image.h"

void Image_Init() {
	numimages = 0;
	images = calloc(numimages+32,sizeof(image_t));
}

void Image_Close() {
	unsigned short i=0;
	while (i < numimages) {
		Engine_DestroyGraphic(images[i].data);
	i++;
	}
	free(images);
}

unsigned short Image_Get(const char*filename) {
	unsigned short i = 0;
	while (i < numimages && images[i].name != NULL) {
		if (strcmp(filename, images[i].name) == 0) {
			return i;
		}
	i++;
	}
	// Couldn't find it, load image and return it
		if (((numimages+1) % 32) == 0) {
			images=realloc(images,sizeof(image_t)*(numimages+32));
		}
	char* fullfilename = calloc(strlen("data/spr/")+1+strlen(filename)+6,sizeof(char));
	strcat(fullfilename,"data/spr/");
	strcat(fullfilename,filename);
	strcat(fullfilename,gfxfextension);
	images[i].data = Engine_LoadGraphic(fullfilename);
	free(fullfilename);
	images[i].name = malloc(strlen(filename) + 1);
	strcpy(images[i].name, filename);
	numimages++;
	return i;
}