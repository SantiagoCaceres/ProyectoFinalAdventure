
#include "Arma.h"

int Arma::getAlcance() const
{
    return alcance;
}

string Arma::getNombre() const
{
    return nombre;
}

void Arma::setDano(int value)
{
    dano = value;
}

void Arma::setAlcance(int value)
{
    alcance = value;
}

void Arma::setProbabilidad(int value)
{
    probabilidad = value;
}

void Arma::setNombre(const string &value)
{
    nombre = value;
}

Arma::Arma(string x, int a, int b,int c ){
    nombre=x;
    dano=a;
    alcance=b;
    probabilidad=c;
    return;
}

void Arma::drop(){
    //Si el jugador mata un enemigo se ejecutará este metodo que definira que item soltar o no soltar ninguno
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

