#include "../globaldef.h"

#ifndef __RENDER__
#define __RENDER__

	//renderer (kek)
	SDL_Renderer* renderer;

	//The window we'll be rendering to
	SDL_Window* window;

	//The surface contained by the window
	SDL_Surface* screenSurface;

	SDL_Event evunion;

	SDL_Texture* game_tex; //holds the actual game part of the screen (which will be drawn to hud then scaled)

	typedef struct {
		SDL_Texture* texture; //the image itself
		unsigned short width;
		unsigned short height;
	} Engine_Texture;

	typedef struct {
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	} rgbacolor_t;

	typedef struct {
		unsigned char r;
		unsigned char g;
		unsigned char b;
	} rgbcolor_t;

	#define make_color_rgb(r,g,b) (rgbcolor_t){r,g,b}



	//FUNCTIONS
	void Renderer_Init();
	void Renderer_Close();
	void EventHandler();
	Engine_Texture* Engine_LoadGraphic(const char* loadgfxfilename);
	void Engine_DestroyGraphic(Engine_Texture* graphic);
	void draw_texture_screen(SDL_Texture* tex);
	void ChangeResScale(float scale);

	void draw_sprite(unsigned short sprite,unsigned short frame,float x,float y);

	#define Renderer_SetDrawColor(r,g,b,a) SDL_SetRenderDrawColor(renderer,r,g,b,a)
	#define Renderer_Clear() SDL_RenderClear(renderer)
	#define Renderer_Present() SDL_RenderPresent(renderer)
	#define Renderer_SetTarget(target) SDL_SetRenderTarget(renderer,target)
	#define Renderer_ResetTarget() SDL_SetRenderTarget(renderer,NULL)
	#define Renderer_SetScale(scx,scy) SDL_RenderSetScale(renderer,scx,scy)
	#define Renderer_ResetScale() SDL_RenderSetScale(renderer,1,1)
	#define Renderer_DrawLine(x1,y1,x2,y2) SDL_RenderDrawLine(renderer,x1,y1,x2,y2)
	#define Renderer_DrawPoint(x,y) SDL_RenderDrawPoint(renderer,x,y)
	#define Renderer_SetLogicalSize(w,h) SDL_RenderSetLogicalSize(renderer,w,h)
	#define Renderer_DrawRect(x,y,w,h) {Renderer_Rect drect = {x,y,w,h}; SDL_RenderDrawRect(renderer,&drect);}
	#define Renderer_FillRect(x,y,w,h) {Renderer_Rect drect = {x,y,w,h}; SDL_RenderFillRect(renderer,&drect);}
#endif