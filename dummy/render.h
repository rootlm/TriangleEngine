#include "../globaldef.h"

#ifndef __RENDER__
#define __RENDER__

	void* game_tex; //holds the actual game part of the screen (which will be drawn to hud then scaled)

	#define Engine_Texture unsigned char

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
	//stubs
	#define Renderer_Init()
	#define Renderer_Close()
	#define EventHandler()
	#define Engine_LoadGraphic(f) NULL
	#define Engine_DestroyGraphic(g)
	#define draw_texture_screen(t)
	#define ChangeResScale(s)

	#define draw_sprite(ds,df,dx,dy)

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
