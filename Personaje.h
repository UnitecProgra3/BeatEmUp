#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Personaje
{
    public:
        list<Personaje*> *personajes;
        vector<SDL_Texture*>texturas;
        SDL_Texture* hitbox_azul;
        SDL_Texture* hitbox_roja;
        SDL_Rect rect,hitbox;
        int frame;
        int animacion;
        bool atacando;

        virtual void draw(SDL_Renderer* renderer);
        virtual void act()=0;
        void init(SDL_Renderer* renderer, list<Personaje*> *personajes);
        bool colision(SDL_Rect param);

        Personaje();
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
