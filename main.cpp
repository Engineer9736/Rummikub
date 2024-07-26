#include <iostream>
#include "main.h"

using namespace std;




//The window we'll be rendering to
SDL_Window* window = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gTileJoker = NULL;
SDL_Surface* gTiles[512];

SDL_Texture* texture;

SDL_Renderer* renderer;

bool mousepressed = false;

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
            

            bool quit = false;
            while( quit == false ) {

                SDL_SetRenderDrawColor(renderer, 18, 96, mousepressed?255:36, 0); // Green background

                SDL_RenderClear(renderer);

                SDL_Point size = getsize(texture);
                SDL_Rect dstrect = { 0, 0, size.x, size.y };
                SDL_RenderCopy(renderer, texture, NULL, &dstrect);

                //SDL_RenderFillRect(rendArg, &screenRect);



                SDL_RenderPresent(renderer);

                // Event handler
                SDL_Event e;
            
                while( SDL_PollEvent( &e ) ) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }

                    if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN) {
                        mousepressed = true;
                            //SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", window);
                    }

                    if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONUP) {
                        mousepressed = false;
                            //SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was released!", window);
                    }
                }
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

SDL_Point getsize(SDL_Texture *texture) {
    SDL_Point size;
    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
    return size;
}

bool init()
{
    //Initialization flag
    bool success = true;
    

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Rummikub", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, 0);
            

            //Get window surface
            //gScreenSurface = SDL_GetWindowSurface( gWindow );
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
    gTiles[0] = SDL_LoadBMP( "C:\\Users\\Richard\\Documents\\RummikubGame\\Rummikub\\images\\tile_blank.bmp" );


    texture = SDL_CreateTextureFromSurface(renderer, gTileJoker);
    

    return success;
}

void close()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    SDL_FreeSurface(gTileJoker);
    gTileJoker = NULL;

    SDL_FreeSurface( gTiles[0] );
    gTiles[0] = NULL;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}