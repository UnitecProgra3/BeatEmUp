#include "Sho.h"

Sho::Sho(SDL_Renderer* renderer)
{
    texturas.push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    SDL_QueryTexture(texturas[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 250;

    frame = 0;
    animacion = 0;
}

void Sho::act()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if(currentKeyStates[SDL_SCANCODE_W])
    {
        rect.y--;
    }

    if(currentKeyStates[SDL_SCANCODE_Z])
    {
        rect.x--;
    }

    if(currentKeyStates[SDL_SCANCODE_S])
    {
        rect.y++;
    }

    if(currentKeyStates[SDL_SCANCODE_D])
    {
        rect.x++;
    }
}

Sho::~Sho()
{
    //dtor
}
