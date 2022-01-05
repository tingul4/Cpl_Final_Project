#ifndef Tile_h
#define Tile_h

#include "Texture.h"

extern const int TILE_WIDTH;
extern const int TILE_HEIGHT;
extern const int TOTAL_TILES;
extern const int TOTAL_TILE_SPRITES;
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern Texture gDotTexture;
extern Texture gTileTexture;
extern SDL_Rect gTileClips[];

class Tile
{
    public:
        //Initializes position and type
        Tile( int x, int y, int tileType );

        //Shows the tile
        void render( SDL_Rect& camera );

        //Get the tile type
        int getType();

        //Get the collision box
        SDL_Rect getBox();

    private:
        //The attributes of the tile
        SDL_Rect mBox;

        //The tile type
        int mType;
};

//Box collision detector
bool checkCollision( SDL_Rect a, SDL_Rect b );

#endif /* Tile_h */
