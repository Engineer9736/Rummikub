#include <iostream>
#include "SDL2\include\SDL.h"

using namespace std;


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gTileJoker = NULL;
SDL_Surface* gTiles[512];

int WinMain() {

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            

            //Apply the image
            SDL_BlitSurface( gTiles[0], NULL, gScreenSurface, NULL );

            //Update the surface
            SDL_UpdateWindowSurface( gWindow );

            

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;
    SDL_Renderer* renderer;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "Rummikub", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {


            // Background color should be 18,96,36

            SDL_Rect screenRect = {0, 0, 800, 600};
            SDL_Renderer* rendArg = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            SDL_SetRenderDrawColor(rendArg, 0xFF, 0x00, 0x00, 0x00);
            SDL_RenderFillRect(rendArg, &screenRect);
            SDL_RenderPresent(rendArg);

            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gTileJoker = SDL_LoadBMP( "C:\\Users\\Richard\\Documents\\RummikubGame\\Rummikub\\images\\tile_joker.bmp" );
    if( gTileJoker == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images\\tile_joker.bmp", SDL_GetError() );
        success = false;
    }

    gTiles[0] = SDL_LoadBMP( "C:\\Users\\Richard\\Documents\\RummikubGame\\Rummikub\\images\\tile_blank.bmp" );

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gTileJoker );
    gTileJoker = NULL;

    SDL_FreeSurface( gTiles[0] );
    gTiles[0] = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}