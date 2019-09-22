#include "enemigo.h"
#include "mapa.h"
#include "item.h"
#include "obstaculo.h"
int main() {
    Arma uno("Excalibur",10,3,100);
    Arma uo("Martillo",2,4,2);
    personaje principal(100,0,20,0,1,uno,'*');
    mapa enemigos;
    enemigos.generar(3,4,principal,uo);
    Obstaculo s(0,21);
    map<vector<int>,Enemigo> r;
    r=enemigos.Get_Mapa();
    while(true){
    char a;
    a = char(_getch());
    if(a=='c'){break;}
    principal.desplazamiento(a);
    s.Dano_Area(r,principal);
    enemigos.enemis_attack();
    principal.estado();
    }
    item a("Botas_Doran");
    a.cualidad();
    return 0;
}

