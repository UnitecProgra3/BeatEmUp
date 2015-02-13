#include "Personaje.h"

Personaje::Personaje()
{
    hitbox.w = 75;
    hitbox.h = 30;
    atacando = false;
}

Personaje::~Personaje()
{
    //dtor
}

void Personaje::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texturas[animacion], NULL, &rect);
    if(frame%100==0)
    {
        animacion++;
        if(animacion>=texturas.size())
            animacion=0;
    }
    hitbox.x = rect.x + rect.w/2 - hitbox.w/2;
    hitbox.y = rect.y + rect.h - hitbox.h/2;
    SDL_RenderCopy(renderer, hitbox_azul, NULL, &hitbox);
    if(atacando)
        SDL_RenderCopy(renderer, hitbox_roja, NULL, &hitbox);
    frame++;

//    hitbox.h++;
//    hitbox.w++;
}
