#include "Sho.h"

Sho::Sho(SDL_Renderer* renderer,list<Personaje*> *personajes)
{
    mapa_texturas["left"] = new vector<SDL_Texture*>();
    mapa_texturas["right"] = new vector<SDL_Texture*>();
    mapa_texturas["walk_right"] = new vector<SDL_Texture*>();
    mapa_texturas["walk_left"] = new vector<SDL_Texture*>();
    mapa_texturas["punch_right"] = new vector<SDL_Texture*>();
    mapa_texturas["punch_left"] = new vector<SDL_Texture*>();

    mapa_texturas["right"]->push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    mapa_texturas["right"]->push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    mapa_texturas["right"]->push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    mapa_texturas["right"]->push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    mapa_texturas["left"]->push_back(IMG_LoadTexture(renderer,"Sho/standing_left/1.png"));
    mapa_texturas["left"]->push_back(IMG_LoadTexture(renderer,"Sho/standing_left/2.png"));
    mapa_texturas["left"]->push_back(IMG_LoadTexture(renderer,"Sho/standing_left/3.png"));
    mapa_texturas["left"]->push_back(IMG_LoadTexture(renderer,"Sho/standing_left/4.png"));

    mapa_texturas["walk_right"]->push_back(IMG_LoadTexture(renderer,"Sho/walk/1.png"));
    mapa_texturas["walk_right"]->push_back(IMG_LoadTexture(renderer,"Sho/walk/2.png"));
    mapa_texturas["walk_right"]->push_back(IMG_LoadTexture(renderer,"Sho/walk/3.png"));
    mapa_texturas["walk_right"]->push_back(IMG_LoadTexture(renderer,"Sho/walk/4.png"));
    mapa_texturas["walk_right"]->push_back(IMG_LoadTexture(renderer,"Sho/walk/5.png"));

    mapa_texturas["walk_left"]->push_back(IMG_LoadTexture(renderer,"Sho/walk_left/1.png"));
    mapa_texturas["walk_left"]->push_back(IMG_LoadTexture(renderer,"Sho/walk_left/2.png"));
    mapa_texturas["walk_left"]->push_back(IMG_LoadTexture(renderer,"Sho/walk_left/3.png"));
    mapa_texturas["walk_left"]->push_back(IMG_LoadTexture(renderer,"Sho/walk_left/4.png"));
    mapa_texturas["walk_left"]->push_back(IMG_LoadTexture(renderer,"Sho/walk_left/5.png"));

    mapa_texturas["punch_right"]->push_back(IMG_LoadTexture(renderer,"Sho/punch/1.png"));
    mapa_texturas["punch_right"]->push_back(IMG_LoadTexture(renderer,"Sho/punch/2.png"));
    mapa_texturas["punch_right"]->push_back(IMG_LoadTexture(renderer,"Sho/punch/3.png"));

    mapa_texturas["punch_left"]->push_back(IMG_LoadTexture(renderer,"Sho/punch_left/1.png"));
    mapa_texturas["punch_left"]->push_back(IMG_LoadTexture(renderer,"Sho/punch_left/2.png"));
    mapa_texturas["punch_left"]->push_back(IMG_LoadTexture(renderer,"Sho/punch_left/3.png"));


    vector_actual_str = "right";

    rect.x = 0;
    rect.y = 0;

    init(renderer,personajes);
}

void Sho::act()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if(currentKeyStates[SDL_SCANCODE_SPACE])
    {
        atacando = true;
        if(vector_actual_str=="walk_right" || vector_actual_str=="right")
        {
            setAnimacion("punch_right");
        }

        if(vector_actual_str=="walk_left" || vector_actual_str=="left")
        {
            setAnimacion("punch_left");
        }
    }else
    {
        atacando = false;
    }

    if(currentKeyStates[SDL_SCANCODE_W])
    {
        rect.y--;
    }
    else if(currentKeyStates[SDL_SCANCODE_S])
    {
        rect.y++;
    }

    if(currentKeyStates[SDL_SCANCODE_D])
    {
        rect.x++;
        setAnimacion("walk_right");
    }
    else if(currentKeyStates[SDL_SCANCODE_Z])
    {
        rect.x--;
        setAnimacion("walk_left");
    }
    else
    {
        if(vector_actual_str == "walk_right")
            vector_actual_str = "right";

        if(vector_actual_str == "walk_left")
            vector_actual_str = "left";
    }

    attackCheck();
}

Sho::~Sho()
{
    //dtor
}
