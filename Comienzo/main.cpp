#include "personaje.h"

int main() {
    Arma uno("Excalibur",10,3,100);
    personaje principal(100,0,20,0,2,uno,'*');
    while(true){
    char a;
    a = _getch();
    if(a=='c'){break;}
    principal.desplazamiento(a);
    principal.estado();
    }
    return 0;
}

