#include "Sho.h"

Sho::Sho(SDL_Renderer* renderer,list<Personaje*> *personajes)
{
    vector<SDL_Texture*>*texturas = new vector<SDL_Texture*>();
    vector<SDL_Texture*>*texturas_left = new vector<SDL_Texture*>();

    texturas->push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    texturas->push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    texturas_left->push_back(IMG_LoadTexture(renderer,"Sho/standing_left/1.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"Sho/standing_left/2.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"Sho/standing_left/3.png"));
    texturas_left->push_back(IMG_LoadTexture(renderer,"Sho/standing_left/4.png"));

    mapa_texturas["left"] = texturas_left;
    mapa_texturas["right"] = texturas;

    vector_actual_str = "right";

    rect.x = 0;
    rect.y = 0;

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
        vector_actual_str = "left";
    }

    if(currentKeyStates[SDL_SCANCODE_S])
    {
        rect.y++;
    }

    if(currentKeyStates[SDL_SCANCODE_D])
    {
        rect.x++;
        vector_actual_str = "right";
    }

    attackCheck();
}

Sho::~Sho()
{
    //dtor
}
