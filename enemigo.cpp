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
    setX(rand());
    setY(rand());
    setX(rand()%111);
    setY(rand()%21);
    desplazamiento('/');
}

void Enemigo::user_attack(){
    //verifica si el jugador esta en rango de ataque, de ser asi realizara la animacion y bajará puntos de vida al jugador
    if(uX>getX() and uY==getY() and uX<=getX()+tipo1->getAlcance() ){
        attack(0,'d');//animacion derecha
        prin->setVida(prin->getVida()-20);
        desplazamiento('/');
        prin->desplazamiento('/');
    }
    else if(uX<getX() and uY==getY() and uX>=getX()-tipo1->getAlcance() ){
        attack(0,'s');//animacion izquierda
        prin->setVida(prin->getVida()-20);
        desplazamiento('/');
        prin->desplazamiento('/');
    }
}
