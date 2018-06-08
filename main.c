//Includes
#include "globaldef.h"
#include "render.h"

//main loop flag
//bool quit = false;


//=======================================================
//Main loop
int main( int argc, char* args[] ) {
	quit = false;
	RendererInit();
	//InitKeys();
	//InitObjects();
	//printf("Input Test - Press Z To Quit\n");

	//InitSprites();

	//testfont=Engine_LoadFont("MSG");

	Engine_Texture* fuck=Engine_LoadGraphic("SprX.png");
	

//------------------------------------------GAME LOOP
	while (!quit) {
		//UpdateKeys();
		//printf("%i %i\n",game->replay.inputpos,game->replay.numinputs);
		//Game_Step();
		//printf("Y:%f\n",objects[0]->y);
		//printf("Object Count:%i\n",objectcount());
		draw_texture_screen(fuck->texture);
		Renderer_Present();
		EventHandler();
	}
	Engine_DestroyGraphic(fuck);

	RendererClose();
	//Game_Quit();
return 0;
}
