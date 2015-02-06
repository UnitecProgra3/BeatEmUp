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
        SDL_Rect rect;
        int frame;
        int animacion_enemigo;

        Enemigo();
        virtual ~Enemigo();

        virtual void draw(SDL_Renderer* renderer);
        virtual void act()=0;

    protected:
    private:
};

#endif // ENEMIGO_H
