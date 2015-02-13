#ifndef ENEMIGO_H
#define ENEMIGO_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <vector>
using namespace std;

class Enemigo
{
    public:
        vector<SDL_Texture*>texturas;
        SDL_Texture* hitbox_azul;
        SDL_Texture* hitbox_roja;
        SDL_Rect rect,hitbox;
        int frame;
        int animacion_enemigo;
        bool atacando;

        Enemigo();
        virtual ~Enemigo();

        virtual void draw(SDL_Renderer* renderer);
        virtual void act()=0;

    protected:
    private:
};

#endif // ENEMIGO_H
