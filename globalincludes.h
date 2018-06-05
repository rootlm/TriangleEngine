#include "globaldef.h"

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

//GLOBAL INCLUDES

#ifdef RENDERER_SDL
	#include <SDL.h>
	#include <SDL_image.h>
	#include <SDL_rwops.h> //for loading textures from memory
	#ifdef INPUT_SDL //just incase i ever make it use sdl for rendering but not input (probably not but eh)
		#include <SDL_keyboard.h>
	#endif

	#define render_h "sdl/render.h"
#endif


#include render_h