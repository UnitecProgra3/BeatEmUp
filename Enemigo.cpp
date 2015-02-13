#include "Enemigo.h"

Enemigo::Enemigo()
{
    //ctor
    hitbox.w = 75;
    hitbox.h = 30;
    atacando = false;
}

Enemigo::~Enemigo()
{
    //dtor
}

void Enemigo::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texturas[animacion_enemigo], NULL, &rect);
    if(frame%100==0)
    {
        animacion_enemigo++;
        if(animacion_enemigo>=texturas.size())
            animacion_enemigo=0;
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
