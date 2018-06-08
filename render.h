#include "globaldef.h"

#ifndef __RENDER__
#define __RENDER__

#ifdef RENDERER_SDL
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
#else
	#define Engine_Texture unsigned char

#endif

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



/*void RendererInit();
void EventHandler();
void ChangeResScale(float scale);
void draw_sprite(short dsprite,unsigned short dsfrm,float dsx,float dsy);
void draw_sprite_ext(short dsprite,unsigned short dsfrm,float dsx,float dsy,float dxsc,float dysc,short dsrot);
void draw_sprite_alpha(short dsprite,unsigned short dsfrm,float dsx,float dsy,float alpha);
void draw_texture(Engine_Texture* tex,short x,short y,float xsc,float ysc);
void draw_texture_screen(Engine_Texture* tex);
Engine_Texture* Engine_LoadGraphic(const char* loadgfxfilename);*/

	//FUNCTIONS
	#ifdef RENDERER_SDL
		void RendererInit();
		void EventHandler();
		Engine_Texture* Engine_LoadGraphic(const char* loadgfxfilename);
		void Engine_DestroyGraphic(Engine_Texture* graphic);
		void draw_texture_screen(SDL_Texture* tex);
		void ChangeResScale(float scale);
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
	#else
		//stubs
		#define RendererInit()
		#define RendererClose()
		#define EventHandler()
		#define Engine_LoadGraphic(f)
		#define Engine_DestroyGraphic(g)
		#define draw_texture_screen(t)
		#define ChangeResScale(s)

		#define Renderer_SetDrawColor(r,g,b,a)
		#define Renderer_Clear()
		#define Renderer_Present()
		#define Renderer_SetTarget(target)
		#define Renderer_ResetTarget()
		#define Renderer_SetScale(scx,scy)
		#define Renderer_ResetScale()
		#define Renderer_DrawLine(x1,y1,x2,y2)
		#define Renderer_DrawPoint(x,y)
		#define Renderer_SetLogicalSize(w,h)
		#define Renderer_DrawRect(x,y,w,h)
		#define Renderer_FillRect(x,y,w,h)
	#endif
#endif