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

void Personaje::init(SDL_Renderer* renderer, list<Personaje*> *personajes)
{
    SDL_QueryTexture(texturas[0], NULL, NULL, &rect.w, &rect.h);

    frame = 0;
    animacion = 0;
    hitbox_azul = IMG_LoadTexture(renderer,"hitbox/azul.png");
    hitbox_roja = IMG_LoadTexture(renderer,"hitbox/roja.png");

    this->personajes = personajes;
}

bool Personaje::colision(SDL_Rect param)
{
    if(param.x + param.w < rect.x
        || param.x > rect.x + rect.w
        || param.y + param.h < rect.y
        || param.y > rect.y + rect.h)
        return false;
    else
        return true;
}



