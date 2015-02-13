#include "EnemigoAzul.h"

EnemigoAzul::EnemigoAzul(SDL_Renderer* renderer)
{
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/4.png"));

    SDL_QueryTexture(texturas[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 250;

    frame = 0;
    animacion = 0;
    hitbox_azul = IMG_LoadTexture(renderer,"hitbox/azul.png");
    hitbox_roja = IMG_LoadTexture(renderer,"hitbox/roja.png");
}

EnemigoAzul::~EnemigoAzul()
{
    //dtor
}

void EnemigoAzul::act()
{
    rect.x++;
    if(frame%100==0)
        atacando = true;
    else
        atacando = false;
}



