	RENDERER_SDL = TRUE
	#RENDERER_DUMMY = TRUE

	ifdef RENDERER_DUMMY
		#OBJS specifies which files to compile as part of the project
		OBJS = main.c math2.c dummy/input.c sprite.c image.c object.c game/gameobjects.c

		#INCLUDE_PATHS specifies the additional include paths we'll need
		INCLUDE_PATHS = -I$(CURDIR)\dummy -I$(CURDIR)\game -I$(CURDIR)\game\objects

		#LIBRARY_PATHS specifies the additional library paths we'll need
		LIBRARY_PATHS = (lib path here)

		#LINKER_FLAGS specifies the libraries we're linking against
		LINKER_FLAGS = -lmingw32
	endif

	ifdef RENDERER_SDL
		#OBJS specifies which files to compile as part of the project
		OBJS = main.c math2.c sdl/render.c sdl/input.c sprite.c image.c object.c game/gameobjects.c

		#INCLUDE_PATHS specifies the additional include paths we'll need
		INCLUDE_PATHS = (SDL2 include path here) -I$(CURDIR)\sdl -I$(CURDIR)\game -I$(CURDIR)\game\objects

		#LIBRARY_PATHS specifies the additional library paths we'll need
		LIBRARY_PATHS = (lib path here)

		#LINKER_FLAGS specifies the libraries we're linking against
		LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	endif

#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
# -g, compile for gdb
COMPILER_FLAGS = -w
#-Wl,-subsystem,windows

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = engine

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
