#include <fstream>
#include "Texture.h"
#include "Dot.h"
#include "Tile.h"
#include "Role.h"

//Screen dimension constants
extern const int SCREEN_WIDTH = 640;
extern const int SCREEN_HEIGHT = 480;

//The dimensions of the level
extern const int LEVEL_WIDTH = 1024;
extern const int LEVEL_HEIGHT = 768;

//Tile constants
extern const int TILE_WIDTH = 64;
extern const int TILE_HEIGHT = 64;
extern const int TOTAL_TILES = 192;
extern const int TOTAL_TILE_SPRITES = 2;

const int ROLE_MOVE_SPRITE = 3;

//The different tile sprites
const int TILE_RED = 0;
const int TILE_GREEN = 1;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia( Tile* tiles[] );

//Frees media and shuts down SDL
void close( Tile* tiles[] );

//Sets tiles from tile map
bool setTiles( Tile *tiles[] );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
Texture gDotTexture;
Texture gTileTexture;
SDL_Rect gTileClips[ TOTAL_TILE_SPRITES ];

SDL_Rect gMoveDownClips[ROLE_MOVE_SPRITE];
SDL_Rect gMoveLeftClips[ROLE_MOVE_SPRITE];
SDL_Rect gMoveRightClips[ROLE_MOVE_SPRITE];
SDL_Rect gMoveUpClips[ROLE_MOVE_SPRITE];

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia( Tile* tiles[] )
{
    //Loading success flag
    bool success = true;

    //Load dot texture
    if( !gDotTexture.loadFromFile( "Role.png" ) )
    {
        cout << "Failed to load dot texture!\n";
        success = false;
    }
    else
    {
        gMoveDownClips[0].x = 144;
        gMoveDownClips[0].y = 192;
        gMoveDownClips[0].w = 48;
        gMoveDownClips[0].h = 48;
        
        gMoveDownClips[1].x = 192;
        gMoveDownClips[1].y = 192;
        gMoveDownClips[1].w = 48;
        gMoveDownClips[1].h = 48;
        
        gMoveDownClips[2].x = 240;
        gMoveDownClips[2].y = 192;
        gMoveDownClips[2].w = 48;
        gMoveDownClips[2].h = 48;
        
        gMoveLeftClips[0].x = 144;
        gMoveLeftClips[0].y = 240;
        gMoveLeftClips[0].w = 48;
        gMoveLeftClips[0].h = 48;
        
        gMoveLeftClips[1].x = 192;
        gMoveLeftClips[1].y = 240;
        gMoveLeftClips[1].w = 48;
        gMoveLeftClips[1].h = 48;
        
        gMoveLeftClips[2].x = 240;
        gMoveLeftClips[2].y = 240;
        gMoveLeftClips[2].w = 48;
        gMoveLeftClips[2].h = 48;
        
        gMoveRightClips[0].x = 144;
        gMoveRightClips[0].y = 288;
        gMoveRightClips[0].w = 48;
        gMoveRightClips[0].h = 48;
        
        gMoveRightClips[1].x = 192;
        gMoveRightClips[1].y = 288;
        gMoveRightClips[1].w = 48;
        gMoveRightClips[1].h = 48;
        
        gMoveRightClips[2].x = 240;
        gMoveRightClips[2].y = 288;
        gMoveRightClips[2].w = 48;
        gMoveRightClips[2].h = 48;
        
        gMoveUpClips[0].x = 144;
        gMoveUpClips[0].y = 336;
        gMoveUpClips[0].w = 48;
        gMoveUpClips[0].h = 48;
        
        gMoveUpClips[1].x = 192;
        gMoveUpClips[1].y = 336;
        gMoveUpClips[1].w = 48;
        gMoveUpClips[1].h = 48;
        
        gMoveUpClips[2].x = 240;
        gMoveUpClips[2].y = 336;
        gMoveUpClips[2].w = 48;
        gMoveUpClips[2].h = 48;
    }

    //Load tile texture
    if( !gTileTexture.loadFromFile( "texture.jpg" ) )
    {
        cout << "Failed to load tile set texture!\n";
        success = false;
    }

    //Load tile map
    if( !setTiles( tiles ) )
    {
        cout << "Failed to load tile set!\n";
        success = false;
    }

    return success;
}

void close( Tile* tiles[] )
{
    //Deallocate tiles
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
         if( tiles[ i ] != NULL )
         {
            delete tiles[ i ];
            tiles[ i ] = NULL;
         }
    }

    //Free loaded images
    gDotTexture.free();
    gTileTexture.free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


bool setTiles( Tile* tiles[] )
{
    //Success flag
    bool tilesLoaded = true;

    //The tile offsets
    int x = 0, y = 0;

    //Open the map
    std::ifstream map( "maze_vector" );

    //If the map couldn't be loaded
    if( map.fail() )
    {
        cout << "Unable to load map file!\n";
        tilesLoaded = false;
    }
    else
    {
        //Initialize the tiles
        for( int i = 0; i < TOTAL_TILES; ++i )
        {
            //Determines what kind of tile will be made
            int tileType = -1;

            //Read tile from map file
            map >> tileType;

            //If the was a problem in reading the map
            if( map.fail() )
            {
                //Stop loading map
                cout << "Error loading map: Unexpected end of file!\n";
                tilesLoaded = false;
                break;
            }

            //If the number is a valid tile number
            if( ( tileType >= 0 ) && ( tileType < TOTAL_TILE_SPRITES ) )
            {
                tiles[ i ] = new Tile( x, y, tileType );
            }
            //If we don't recognize the tile type
            else
            {
                //Stop loading map
                cout << "Error loading map: Invalid tile type at " << i << endl;
                tilesLoaded = false;
                break;
            }

            //Move to next tile spot
            x += TILE_WIDTH;

            //If we've gone too far
            if( x >= LEVEL_WIDTH )
            {
                //Move back
                x = 0;

                //Move to the next row
                y += TILE_HEIGHT;
            }
        }
        
        //Clip the sprite sheet
        if( tilesLoaded )
        {
            gTileClips[ TILE_RED ].x = 0;
            gTileClips[ TILE_RED ].y = 0;
            gTileClips[ TILE_RED ].w = TILE_WIDTH;
            gTileClips[ TILE_RED ].h = TILE_HEIGHT;

            gTileClips[ TILE_GREEN ].x = 0;
            gTileClips[ TILE_GREEN ].y = 64;
            gTileClips[ TILE_GREEN ].w = TILE_WIDTH;
            gTileClips[ TILE_GREEN ].h = TILE_HEIGHT;
        }
    }

    //Close the file
    map.close();

    //If the map was loaded fine
    return tilesLoaded;
}


int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
        cout << "Failed to initialize!\n";
    else
    {
        //The level tiles
        Tile* tileSet[ TOTAL_TILES ];

        //Load media
        if( !loadMedia( tileSet ) )
            cout << "Failed to load media!\n";
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //The dot that will be moving around on the screen
            Role role;

            //Level camera
            SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
            
            int frame = 0;

            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

                    //Handle input for the dot
                    role.handleEvent( e );
                }
                
                //Move the dot
                role.move( tileSet );
                role.setCamera( camera );

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Render level
                for( int i = 0; i < TOTAL_TILES; ++i )
                {
                    tileSet[ i ]->render( camera );
                }

                //Render dot
                role.render( camera, frame );
                
                ++frame;
                if (frame/4 >= ROLE_MOVE_SPRITE)
                    frame = 0;
                
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
        
        //Free resources and close SDL
        close( tileSet );
    }

    return 0;
}
