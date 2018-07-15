#include "../globaldef.h"
#include "render.h"
#include "../sprite.h"
#include "../image.h"

	void Renderer_Init() {
		//Initialize SDL
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		{
			printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		}
		else {
			printf("SDL Initialized!\n");
			//Create window
			window = SDL_CreateWindow( APPTITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
			if( window == NULL ) {
				printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			}
			else {
				printf("Window created successfully!\n");
				//Get window surface
				screenSurface = SDL_GetWindowSurface( window );
			}
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

		if( renderer == NULL ) {
				printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else {
		printf("Renderer created successfully!\n");
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		game_tex = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,GAME_WIDTH,GAME_HEIGHT);
	
		//SDL_SetWindowSize(window,640,480);
		//Init SDL_Image
		int initimgflags=IMG_INIT_PNG;
		IMG_Init(initimgflags);
	}

	void Renderer_Close() {
		if (game_tex != NULL) {
			SDL_DestroyTexture(game_tex);
		}
		IMG_Quit();
		SDL_Quit();
	}

	void EventHandler() {
		while (SDL_PollEvent(&evunion) != 0) {
			//User requests quit
			if (evunion.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	Engine_Texture* Engine_LoadGraphic(const char* loadgfxfilename) {

		Engine_Texture* newTexture = calloc(1,sizeof(Engine_Texture));

		SDL_Surface* loadedSurface = IMG_Load(loadgfxfilename);

		if (loadedSurface == NULL) {
			printf( "Texture %s could not be created! SDL_Error: %s\n", loadgfxfilename, SDL_GetError() );
		}
		else {
			printf( "Texture %s loaded! \n", loadgfxfilename );
		}

		newTexture->texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		SDL_FreeSurface(loadedSurface);

		int tw,th;

		SDL_QueryTexture(newTexture->texture,NULL,NULL,&tw,&th);

		newTexture->width=tw;
		newTexture->height=th;

	return newTexture;
	}

	void Engine_DestroyGraphic(Engine_Texture* graphic) {
		//printf("%i\n",graphic);
		printf("%i\n",graphic->texture);
		SDL_DestroyTexture(graphic->texture);
		printf("%i\n",graphic);
		printf("%i\n",graphic->texture);
		free(graphic);
	}

	void draw_texture_screen(SDL_Texture* tex) {
		SDL_RenderCopy(renderer,tex,NULL,NULL);
	}

	void ChangeResScale(float scale) {
		SDL_DestroyTexture(game_tex);
		SDL_SetWindowSize(window,SCREEN_WIDTH*scale,SCREEN_HEIGHT*scale);
		game_tex = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,GAME_WIDTH,GAME_HEIGHT);
	}

	//--sprite drawing functions--
	void draw_sprite(unsigned short sprite,unsigned short frame,float x,float y) {
		SDL_Point sproff;
		SDL_Rect destrect,frect;

		sproff.x=sprites[sprite].data.xoff;
		sproff.y=sprites[sprite].data.yoff;
		memcpy(&frect,&sprites[sprite].data.framerect,sizeof(SDL_Rect));

		destrect.x = x-sproff.x;
		destrect.y = y-sproff.y;
		destrect.w = sprites[sprite].data.framerect.w;
		destrect.h = sprites[sprite].data.framerect.h;

		if (sprites[sprite].data.animlength == 0) {
			frame = 0; //modulo by 0 means rip so 
		}
		else if (frame > sprites[sprite].data.animlength) {
			frame = frame % (sprites[sprite].data.animlength+1); //make sure the frame number is within the animation length!
		}

		//set part of image to draw based off frame
		if (sprites[sprite].data.animlength != 0 && sprites[sprite].data.anim != NULL) {
			frect.x += sprites[sprite].data.framerect.w * sprites[sprite].data.anim[frame];
		}
		SDL_RenderCopyEx(renderer,images[sprites[sprite].sheet].data->texture,&frect,&destrect,0,&sproff,SDL_FLIP_NONE);
	}
