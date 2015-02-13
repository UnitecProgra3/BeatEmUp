#include "Sho.h"

Sho::Sho(SDL_Renderer* renderer,list<Personaje*> *personajes)
{
    texturas.push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    rect.x = 100;
    rect.y = 250;

    init(renderer,personajes);
}

void Sho::act()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    atacando = currentKeyStates[SDL_SCANCODE_SPACE];

    if(currentKeyStates[SDL_SCANCODE_W])
    {
        rect.y--;
    }

    if(currentKeyStates[SDL_SCANCODE_Z])
    {
        rect.x--;
    }

    if(currentKeyStates[SDL_SCANCODE_S])
    {
        rect.y++;
    }

    if(currentKeyStates[SDL_SCANCODE_D])
    {
        rect.x++;
    }

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
                if(colision((*i)->rect))
                {
                    cout<<"Colision! "<< frame <<endl;
                }
            }
        }
    }
}

Sho::~Sho()
{
    //dtor
}
