#ifndef role_h
#define role_h

#include "Dot.h"

class Role : public Dot
{
    public:
        Role();
        void handleEvent( SDL_Event& e );
        void render( SDL_Rect& camera, int& frame );
};

#endif /* Role_h */
