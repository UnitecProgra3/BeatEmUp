#include "EnemigoAzul.h"

EnemigoAzul::EnemigoAzul(SDL_Renderer* renderer, list<Personaje*> *personajes)
{
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoAzul/standing/4.png"));

    rect.x = 100;
    rect.y = 250;

    init(renderer,personajes);
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



