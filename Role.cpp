#include "Role.h"

Role::Role()
{
    mBox.x = 64;
    mBox.y = 64;
    mBox.w = DOT_WIDTH;
    mBox.h = DOT_HEIGHT;

    mVelX = 0;
    mVelY = 0;
}

void Role::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; state = 3; break;
            case SDLK_DOWN: mVelY += DOT_VEL; state = 0; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; state = 1; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; state = 2; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY -= DOT_VEL; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void Role::render( SDL_Rect& camera, int& frame )
{
    //Show the dot
    SDL_Rect *currentClip;
    if (mVelX == 0 && mVelY == 0)
        frame = 4;
    switch (state)
    {
        case 0: currentClip = &gMoveDownClips[frame/4]; break;
        case 1: currentClip = &gMoveLeftClips[frame/4]; break;
        case 2: currentClip = &gMoveRightClips[frame/4]; break;
        case 3: currentClip = &gMoveUpClips[frame/4]; break;
    }
    gDotTexture.render( mBox.x - camera.x, mBox.y - camera.y, currentClip );
}
