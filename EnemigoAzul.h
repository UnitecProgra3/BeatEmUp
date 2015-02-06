#ifndef ENEMIGOAZUL_H
#define ENEMIGOAZUL_H

#include "Enemigo.h"

class EnemigoAzul : public Enemigo
{
    public:
        EnemigoAzul(SDL_Renderer* renderer);
        virtual ~EnemigoAzul();

        void act();
    protected:
    private:
};

#endif // ENEMIGOAZUL_H
