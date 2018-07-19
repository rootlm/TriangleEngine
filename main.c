//Includes
#include "globaldef.h"

#include "render.h"
#include "input.h"
#include "sprite.h"
#include "image.h"
#include "object.h"
#include "game/gameobjects.h"
#include "math2.h"

//=======================================================
//Main loop
int main( int argc, char* args[] ) {
	quit = false;
		Renderer_Init();
		Input_Init();
		Image_Init();
		Sprite_Init();

		Object_Init();
		
		unsigned short spr=Sprite_Get("SPR_ERROR");
		unsigned short timer=0;
	while (!quit) {
		Input_Update();
		Objects_Update();

			Renderer_SetTarget(game_tex);
			Renderer_Clear();
			timer++;
			if (timer%29 == 0) {
				Object_Create(-32,0,0);
			}
			//draw_sprite_ext(spr,timer/4,480/2,360/2,2+dsin(timer*3)*1,2+dsin(timer*3)*1,timer);
			draw_sprite_ext(spr,timer/4,480/2,360/2,3,3,timer);
			Objects_Draw();
			Renderer_ResetTarget();

		draw_texture_screen(game_tex);
		Renderer_Present();

		EventHandler();
	}
	Sprite_Close();
	Image_Close();

	Object_Close();

	Input_Close();
	Renderer_Close();
return 0;
}
