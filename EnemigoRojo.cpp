#include "EnemigoRojo.h"

EnemigoRojo::EnemigoRojo(SDL_Renderer* renderer, list<Personaje*> *personajes)
{
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/4.png"));

    rect.x = 750;
    rect.y = 250;

    init(renderer, personajes);
}

EnemigoRojo::~EnemigoRojo()
{
    //dtor
}

void EnemigoRojo::act()
{
    rect.x--;
}
