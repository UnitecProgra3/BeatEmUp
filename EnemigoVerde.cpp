#include "EnemigoVerde.h"

EnemigoVerde::EnemigoVerde(SDL_Renderer* renderer, list<Personaje*> *personajes)
{
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing/4.png"));

    texturas_left.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing_left/1.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing_left/2.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing_left/3.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer,"EnemigoVerde/standing_left/4.png"));

    rect.x = 500;
    rect.y = 250;

    init(renderer, personajes);
}

EnemigoVerde::~EnemigoVerde()
{
    //dtor
}

void EnemigoVerde::act()
{
    rect.y++;
}
