
#include "Arma.h"

Arma::Arma(string x, int a, int b,int c ){
    nombre=x;
    dano=a;
    alcance=b;
    probabilidad=c;
    return;
}

void Arma::drop(){
fstream Armas;
string texto;
Armas.open("Armas.txt",ios::in);
int num,numu;
srand(time(NULL));
numu=rand();
numu=rand()%100;
num = rand();
 num=rand()%20;
 
 if(numu<=probabilidad){
    for(int i=0;i<=num;i++){
    getline(Armas,texto);
    }
    cout<<texto<<endl;//Dropeo de arma con probabilidad
 }



}

