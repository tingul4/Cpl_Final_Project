#ifndef Dot_h
#define Dot_h

#include "Texture.h"
#include "Tile.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int LEVEL_WIDTH;
extern const int LEVEL_HEIGHT;
extern const int TOTAL_TILES;
extern const int TOTAL_TILE_SPRITES;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern Texture gDotTexture;
extern SDL_Rect gMoveDownClips[];
extern SDL_Rect gMoveLeftClips[];
extern SDL_Rect gMoveRightClips[];
extern SDL_Rect gMoveUpClips[];

class Dot
{
    public:
        //The dimensions of the dot
        static const int DOT_WIDTH = 48;
        static const int DOT_HEIGHT = 48;

        //Maximum axis velocity of the dot
        static const int DOT_VEL = 3;

        //Initializes the variables
        Dot();

        //Takes key presses and adjusts the dot's velocity
        void handleEvent( SDL_Event& e );

        //Moves the dot and check collision against tiles
        void move( Tile *tiles[] );

        //Centers the camera over the dot
        void setCamera( SDL_Rect& camera );

        //Shows the dot on the screen
        void render( SDL_Rect& camera, int& frame );
    protected:
        //Collision box of the dot
        SDL_Rect mBox;

        //The velocity of the dot
        int mVelX, mVelY, state;
};

//Checks collision box against set of tiles
bool touchesWall( SDL_Rect box, Tile* tiles[] );

#endif /* Dot_h */
