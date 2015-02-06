#include "EnemigoVerde.h"

EnemigoVerde::EnemigoVerde(SDL_Renderer* renderer)
{
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/4.png"));

    SDL_QueryTexture(texturas[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 500;
    rect.y = 250;

    frame = 0;
    animacion_enemigo = 0;
}

EnemigoVerde::~EnemigoVerde()
{
    //dtor
}

void EnemigoVerde::act()
{
    rect.y++;
}
