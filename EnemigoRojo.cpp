#include "EnemigoRojo.h"

EnemigoRojo::EnemigoRojo(SDL_Renderer* renderer)
{
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/4.png"));

    SDL_QueryTexture(texturas[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 750;
    rect.y = 250;

    frame = 0;
    animacion_enemigo = 0;
}

EnemigoRojo::~EnemigoRojo()
{
    //dtor
}

void EnemigoRojo::act()
{
    rect.x--;
}
