#include "EnemigoRojo.h"

EnemigoRojo::EnemigoRojo(SDL_Renderer* renderer, list<Personaje*> *personajes)
{
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing/4.png"));

    texturas_left.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing_left/1.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing_left/2.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing_left/3.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer,"EnemigoRojo/standing_left/4.png"));

    mapa_texturas["left"]=&texturas_left;
    mapa_texturas["right"]=&texturas;

    textura_actual = "right";

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
