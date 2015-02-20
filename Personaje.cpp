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
    SDL_RenderCopy(renderer, texturas_left[animacion], NULL, &rect);
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

    muerto = false;
}

bool Personaje::colision(SDL_Rect param)
{
    if(param.x + param.w < hitbox.x
        || param.x > hitbox.x + hitbox.w
        || param.y + param.h < hitbox.y
        || param.y > hitbox.y + hitbox.h)
        return false;
    else
        return true;
}

void Personaje::attackCheck()
{
    if(atacando)
    {
        //detecto colision con los demas personajes
        list<Personaje*>::iterator i;
        for(i= personajes->begin();
            i!=personajes->end();
            i++)
        {
            if((*i)!=this)
            {
                if(colision((*i)->hitbox))
                {
                    cout<<"Colision! "<< frame <<endl;
                    //personajes->erase(i);
                    (*i)->muerto = true;
                }
            }
        }
    }
}
