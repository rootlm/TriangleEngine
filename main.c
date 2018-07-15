//Includes
#include "globaldef.h"

#include "render.h"
#include "input.h"
#include "sprite.h"
#include "image.h"

//=======================================================
//Main loop
int main( int argc, char* args[] ) {
	quit = false;
		Renderer_Init();
		Input_Init();

		//Engine_Texture* fuck=Engine_LoadGraphic("SprX.png");
		Image_Init();
		Sprite_Init();
		unsigned short spr=Sprite_Get("SPR_PLAYER");
	while (!quit) {
		Input_Update();
		if (keyboard_check_pressed(SDL_SCANCODE_Z)) {
			quit = true;
		}
			Renderer_SetTarget(game_tex);
			//draw_texture_screen(images[sprites[spr].sheet].data->texture);
			//draw_texture_screen(fuck->texture);
			draw_sprite(spr,0,64,64);
			Renderer_ResetTarget();
		draw_texture_screen(game_tex);
		Renderer_Present();

		EventHandler();
	}
	Sprite_Close();
	Image_Close();
	//Engine_DestroyGraphic(fuck);

	Input_Close();
	Renderer_Close();
return 0;
}
