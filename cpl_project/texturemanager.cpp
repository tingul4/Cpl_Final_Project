#include "game.h"
#include "texturemanager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filePath)
{
    SDL_Surface* tmpSurface = IMG_Load( filePath );
    SDL_Texture* tex = NULL;
    if( tmpSurface != NULL )
    {
        SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 32, 192, 64 ) );

        //Create texture from surface pixels
        tex = SDL_CreateTextureFromSurface( renderer, tmpSurface );
    }
    SDL_FreeSurface(tmpSurface);
    return tex;
}
void TextureManager::Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}
