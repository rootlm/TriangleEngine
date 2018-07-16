//Includes
#include "globaldef.h"

#include "render.h"
#include "input.h"
#include "sprite.h"
#include "image.h"
#include "object.h"
#include "game/gameobjects.h"

//=======================================================
//Main loop
int main( int argc, char* args[] ) {
	quit = false;
		Renderer_Init();
		Input_Init();
		Image_Init();
		Sprite_Init();

		Object_Init();
		Object_Create(0,0,0);
	while (!quit) {
		Input_Update();
		Objects_Update();

			Renderer_SetTarget(game_tex);
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
