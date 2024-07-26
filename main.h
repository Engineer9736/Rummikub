#include "SDL2\include\SDL.h"

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

SDL_Point getsize(SDL_Texture*);
