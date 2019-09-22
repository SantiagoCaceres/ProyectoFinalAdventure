#ifndef MAP_H
#define MAP_H
#include <vector>
#include "personaje.h"
#include <map>
#include "enemigo.h"

class mapa
{
    private:
    map<vector<int>,Enemigo> posiciones;
    personaje *prin;
public:

    void generar(int enemigos, int nivel,personaje &principal,Arma &a);
    void enemis_attack();

};

#endif // MAP_H