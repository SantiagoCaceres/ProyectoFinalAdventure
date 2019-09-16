#include <string>
#include <iostream>
#include <cstdlib>
#include "Arma.h"

using namespace std;

class personaje{
private:
    int vida,experiencia,defensa,nivel,velocidad;
    Arma tipo1;
    char cuerpo;
public:
    

};


int main() {
    Arma uno("Excalibur",10,3,100);
    uno.drop();
    return 0;
}

