#ifndef ENEMIGOVERDE_H
#define ENEMIGOVERDE_H

#include "Enemigo.h"

class EnemigoVerde : public Enemigo
{
    public:
        EnemigoVerde(SDL_Renderer* renderer);
        virtual ~EnemigoVerde();
        void act();
    protected:
    private:
};

#endif // ENEMIGOVERDE_H
