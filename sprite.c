#include "render.h"
#include "sprite.h"

void Sprite_Init() {
	numsprites = 0;
	sprites = calloc(numsprites+32,sizeof(sprite_t));
}

void Sprite_Close() {
	unsigned short i=0;
	while (i < numsprites) {
		if (sprites[i].data.animlength > 0 && sprites[i].data.anim != NULL) {
			free(sprites[i].data.anim);
		}
		if (sprites[i].name != NULL) {
			free(sprites[i].name);
		}
		if (sprites[i].sheetname != NULL) {
			free(sprites[i].sheetname);
		}
	i++;
	}
	free(sprites);
}

spritedata_t Sprite_Load(const char* filename,char** sheetnameloc) {
	char* namecopy = calloc(strlen("data/spr/")+1+strlen(filename)+1+5,sizeof(char));
	strcat(namecopy,"data/spr/");
	strcat(namecopy,filename);
	strcat(namecopy,".spr");

	spritedata_t data;
	data.framerect = (Renderer_Rect){0,0,0,0};
	

	FILE* file = fopen(namecopy,"r");
	if (file == NULL) { //doesn't exist, try to load SPR_ERROR instead
		file = fopen("data/spr/SPR_ERROR.spr","r");
		if (file == NULL) {
			#ifdef RENDERER_SDL
				SDL_ShowSimpleMessageBox(0,"lol","What's wrong with you?",window);
			#endif
			return data;
		}
	}

	if (namecopy != NULL) {
		free(namecopy);
	}

	if (file != NULL) {
		fread(&data.framerect.x,2,1,file);
		fread(&data.framerect.y,2,1,file);
		fread(&data.framerect.w,2,1,file);
		fread(&data.framerect.h,2,1,file);
		fread(&data.animlength,1,1,file);
		fread(&data.xoff,2,1,file);
		fread(&data.yoff,2,1,file);

		//read anims
		if (data.animlength > 0) {
			data.anim = calloc(data.animlength,sizeof(unsigned char));
			fread(data.anim,data.animlength,1,file);
		}
		
		//sheet name
		unsigned char namelen;
		fread(&namelen,1,1,file);
		char* sheetname = calloc(namelen+1,sizeof(char));

		*sheetnameloc = sheetname;

		bool loadedstr = false;
		unsigned char i=0;

		char tempchar[2];
		tempchar[1]=0;

            	while (loadedstr == false && i < namelen) {
			fread(tempchar,1,1,file);
                	if (tempchar[0] == 0) {
                    		loadedstr=true;
                	}
                	else {
                    		strcat(sheetname,tempchar);
               		}
            	}
		fclose(file);
	}

return data;
}

unsigned short Sprite_Get(const char*filename) {
	unsigned short i = 0;
	while (i < numsprites && sprites[i].name != NULL) {
		if (strcmp(filename, sprites[i].name) == 0) {
			return i;
		}
	i++;
	}
	// Couldn't find it, load image and return it
		if (((numsprites+1) % 32) == 0) {
			sprites=realloc(sprites,sizeof(sprite_t)*(numsprites+32));
		}
	sprites[i].data = Sprite_Load(filename,&sprites[i].sheetname);
	sprites[i].name = malloc(strlen(filename) + 1);
	strcpy(sprites[i].name, filename);
	sprites[i].sheet = Image_Get(sprites[i].sheetname);
	numsprites++;
	return i;
}