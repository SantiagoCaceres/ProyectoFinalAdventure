#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "mapa.h"

class Obstaculo
{
private:
    int ancho=50;
    int largo=1;
    int x,y;
    int Velocidad=0;
    int Dano=10;
public:
    Obstaculo(int a,int b);
    void Dano_Area(map<vector<int>,Enemigo> &a,personaje &principal);
};
//El void movimiento quedará pendiente para cuando este bien definida las formulas fisicas
#endif // OBSTACULO_H
