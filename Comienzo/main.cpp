#include "enemigo.h"
#include "mapa.h"
//Especial consola
int main() {
    Arma uno("Excalibur",10,3,100);
    Arma uo("Martillo",2,4,2);
    personaje principal(100,0,20,0,1,uno,'*');
    mapa enemigos;
    enemigos.generar(3,4,principal,uo);
    while(true){
    char a;
    a = char(_getch());
    if(a=='c'){break;}
    principal.desplazamiento(a);
    enemigos.enemis_attack();
    principal.estado();
    }
    return 0;
}

