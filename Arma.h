#include    <string>
#include    <stdlib.h>
#include    <time.h>
#include    <fstream>
#include    <iostream>
#ifndef ARMA_H
#define ARMA_H
using namespace std;

class Arma{
private:
    string nombre;
    int dano,alcance,probabilidad;
public:
    Arma(string,int,int,int);
    void drop();
    int getAlcance() const;
    string getNombre() const;
    void setDano(int value);
    void setAlcance(int value);
    void setProbabilidad(int value);
    void setNombre(const string &value);
};

#endif /* ARMA_H */

