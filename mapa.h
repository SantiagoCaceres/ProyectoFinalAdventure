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
    map<vector<int>,Enemigo> Get_Mapa(){
        return posiciones;
    }

    void setPosiciones(const map<vector<int>, Enemigo> &value);
};

#endif // MAP_H
