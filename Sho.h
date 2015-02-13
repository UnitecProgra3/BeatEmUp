#ifndef SHO_H
#define SHO_H

#include "Personaje.h"

class Sho : public Personaje
{
    public:
        Sho(SDL_Renderer* renderer,list<Personaje*> *personajes);
        void act();
        virtual ~Sho();
    protected:
    private:
};

#endif // SHO_H
