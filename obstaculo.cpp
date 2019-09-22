#include "obstaculo.h"
void gotox(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}
Obstaculo::Obstaculo(int a, int b)
{
x=a;
y=b;
}

void Obstaculo::Dano_Area(map<vector<int>,Enemigo> &a,personaje &principal){
    for(int i=0;i<largo;i++){
        gotox(x,y+i);
        for(int j=0;j<ancho;j++){
        cout<<"=";}

    }
    for(int i=0;i<ancho;i++){
        if(principal.getY()==y-1){
            if(principal.getX()==x+i){
                principal.setVida(principal.getVida()-10);
            }
        }
        for(auto j=a.begin();j!=a.end();j++){
            if(j->first.at(1)==y-1){
                if(x+i==j->first.at(0)){
                    j->second.setVida(j->second.getVida()-10);

                    //j->second.estado(); mejorar porque no morira de la misma forma que el usuario
                }
            }
        }
    }
}
