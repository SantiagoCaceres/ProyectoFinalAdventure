#include "mapa.h"

void mapa::generar(int enemigos, int nivel,personaje &principal,Arma &uno){
    //Esta funcion se encarga de generar el mapa, con las posiciones del usuario y un arma para darle a los enemigos
    prin=&principal;
    vector<int> a;
    srand(time(NULL));
    for(int i=0;i<enemigos;i++){//Se genera una cantidad de enemigos con posiciones aleatorias
        Enemigo z(100*nivel,0,20*nivel,0,2,uno,'+',2,*prin);

        z.generar_posicion();
        z.setUX(principal.getX());
        z.setUY(principal.getY());
        a.push_back(z.getX());
        a.push_back(z.getY());
       posiciones.insert(pair<vector<int>,Enemigo>(a,z));
       if(posiciones.size()<enemigos){i=0;}
       else {
           break;
       }
       a.clear();
    }


}

void mapa::enemis_attack(){
    //Verifica si el usuario esta en rango de ataque de algun enemigo, de ser asi este atacará y realizara daño al jugador
    for (auto i=posiciones.begin();i!=posiciones.end();i++) {
        i->second.setUX(prin->getX());
        i->second.setUY(prin->getY());
        i->second.user_attack();
    }
}
