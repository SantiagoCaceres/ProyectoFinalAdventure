#include "enemigo.h"


void Enemigo::setUX(int value)
{
    uX = value;
}

void Enemigo::setUY(int value)
{
    uY = value;
}

Enemigo::Enemigo(int a,int b,int c,int d,int e,Arma &x,char z,int n,personaje &principal):personaje(a*n,b*n,c*n,d*n,e*n,x,z){
prin=&principal;
}

void Enemigo::generar_posicion(){
    srand(time(NULL));
    setX(rand());
    setY(rand());
    setX(rand()%21);
    setY(rand()%21);
    desplazamiento('/');
}

void Enemigo::user_attack(){
    if(uX>getX() and uY==getY() and uX<=getX()+tipo1->getAlcance() ){
        attack(0);
        prin->setVida(prin->getVida()-20);
        desplazamiento('/');
        prin->desplazamiento('/');
    }
}
