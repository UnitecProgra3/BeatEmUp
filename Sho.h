#ifndef SHO_H
#define SHO_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <vector>
using namespace std;

class Sho
{
    public:
        vector<SDL_Texture*>sho_standing;
        SDL_Rect rect;
        int frame;
        int animacion_sho;
        Sho(SDL_Renderer* renderer);
        void draw(SDL_Renderer* renderer);
        void act();
        virtual ~Sho();
    protected:
    private:
};

#endif // SHO_H
