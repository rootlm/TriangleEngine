#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


#ifndef __GLOBALDEF__
#define __GLOBALDEF__
	//these are global defines
	//Screen dimension constants
	#define SCREEN_WIDTH 960
	#define SCREEN_HEIGHT 720

	//#define GAME_WIDTH 320
	//#define GAME_HEIGHT 240

	#define GAME_WIDTH 480
	#define GAME_HEIGHT 360
	#define APPTITLE "Triangle Engine"

	bool quit;

	#define GAME_STATE_INGAME 0
	#define GAME_STATE_PAUSED 1
	#define GAME_STATE_MENU 10
	//unsigned char GAME_STATE;

	#define DEBUG

	//define data folders
	#define sprfolder "data/spr/"
	#define fontfolder "data/fonts/"
	#define stagefolder "data/stg/"

	#define replayfolder "replay/"

	//and file extensions?
	#define gfxfextension ".png"
	#define sprfextension ".png"
	#define replayfextension ".rpl"

	/*Platform list (not that all of these will get implemented just define names for IF they get implemented:
	PLATFORM_PC:take a guess
	PLATFORM_3DSHB:3DS Homebrew
	PLATFORM_SWHB:Switch Homebrew
	PLATFORM_PS1:whaddya think
	PLATFORM_PSP:duh
	*/

	//platform 
	#define PLATFORM_PC

	//renderer (the idea is that if you don't define a renderer the game will run but you won't be able to see anything obviously)
	//requires changing this and the first thing in the makefile too
	#define RENDERER_SDL

	/* list:
	RENDERER_SDL (duh)
	RENDERER_DUMMY (doesn't display anything or take input obviously)
	*/

	//renderer typedefs
	#ifdef RENDERER_SDL
		#include <SDL.h>
		#include <SDL_image.h>
		#define Renderer_Texture SDL_Texture
		#define Renderer_Rect SDL_Rect
		#define INPUT_SDL //input is seperate from rendering but if using sdl for rendering might as well use it for keyboard too
	#else
		#define Renderer_Texture unsigned char
		typedef struct {
			unsigned short x;
			unsigned short y;
			unsigned short w;
			unsigned short h;
		} Renderer_Rect;
	#endif

#endif

//GLOBAL LIBRARY includes

#ifdef RENDERER_SDL
	#include <SDL.h>
	#include <SDL_image.h>
#endif