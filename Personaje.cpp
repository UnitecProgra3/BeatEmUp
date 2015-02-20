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
    vector<SDL_Texture*> *vector_textura_actual_temp = mapa_texturas[textura_actual];

    SDL_Texture* textura_actual_temp = (*vector_textura_actual_temp)[animacion];

    SDL_QueryTexture( textura_actual_temp, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, textura_actual_temp, NULL, &rect);
    if(frame%100==0)
    {
        animacion++;
        if(animacion>=(*vector_textura_actual_temp).size())
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
                    cout<< (*i)->hitbox.x <<endl;
                    cout<< (*i)->hitbox.y <<endl;
                    cout<< (*i)->hitbox.w <<endl;
                    cout<< (*i)->hitbox.h <<endl;
                    cout<< hitbox.x <<endl;
                    cout<< hitbox.y <<endl;
                    cout<< hitbox.w <<endl;
                    cout<< hitbox.h <<endl;
                    //personajes->erase(i);
                    (*i)->muerto = true;
                }
            }
        }
    }
}
