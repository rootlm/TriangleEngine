#include "globaldef.h"
#include "render.h"

#ifdef RENDERER_SDL //sdl (duh)
	void RendererInit() {
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

		//game_tex = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,GAME_WIDTH,GAME_HEIGHT);
	
		//SDL_SetWindowSize(window,640,480);
		//Init SDL_Image
		int initimgflags=IMG_INIT_PNG;
		IMG_Init(initimgflags);
	}

	void RendererClose() {
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

#endif