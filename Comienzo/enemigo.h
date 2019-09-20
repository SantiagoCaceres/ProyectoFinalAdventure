#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"
#include<time.h>
#include<stdlib.h>


class Enemigo: public personaje
{
    private:
    int uX;
    int uY;
    personaje *prin;
    public:
    Enemigo(int a,int b,int c,int d,int e,Arma &x,char z,int n,personaje &principal);

    void generar_posicion();
    void user_attack();

    void setUX(int value);
    void setUY(int value);
};

#endif // ENEMIGO_H
