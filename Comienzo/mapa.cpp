#include "mapa.h"

void mapa::generar(int enemigos, int nivel,personaje &principal,Arma &uno){
    prin=&principal;
    vector<int> a;

    for(int i=0;i<enemigos;i++){
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
    for (auto i=posiciones.begin();i!=posiciones.end();i++) {
        i->second.setUX(prin->getX());
        i->second.setUY(prin->getY());
        i->second.user_attack();
    }
}
