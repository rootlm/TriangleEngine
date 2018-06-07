//Includes
#include "globaldef.h"
#include "render.h"

//main loop flag
//bool quit = false;


//=======================================================
//Main loop
int main( int argc, char* args[] )
{
	quit = false;
	RendererInit();
	//InitKeys();
	//InitObjects();
	//printf("Input Test - Press Z To Quit\n");

	//InitSprites();

	//testfont=Engine_LoadFont("MSG");
	

//------------------------------------------GAME LOOP
	while (!quit) {
		EventHandler();
		//UpdateKeys();
		//printf("%i %i\n",game->replay.inputpos,game->replay.numinputs);
		//Game_Step();
		//printf("Y:%f\n",objects[0]->y);
		//printf("Object Count:%i\n",objectcount());
	}

	RendererClose();
	//Game_Quit();
return 0;
}
