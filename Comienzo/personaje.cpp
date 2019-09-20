#include "personaje.h"

//Especial consola
void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}
//Especial consola


void personaje::setY(int value)
{
    y = value;
}

void personaje::setX(int value)
{
    x = value;
}

int personaje::getY() const
{
    return y;
}

int personaje::getX() const
{
    return x;
}

char personaje::getCuerpo() const
{
    return cuerpo;
}

void personaje::setVida(int value)
{
    vida = value;
}

int personaje::getVida() const
{
    return vida;
}

personaje::personaje(int a,int b,int c,int d,int e,Arma &x,char z){
    vida=a;
    experiencia=b;
    defensa=c;
    nivel=d;
    velocidad=e;
    tipo1=&x;
    cuerpo=z;
}

int personaje::estado(){
    if(vida<=0){
        cout<<"Acabas de morir"<<endl;//desplegar mensaje si es el personaje del usuario
        system("pause");
        system("CLS");
        respawn();
        return(1);

    }
}


void personaje::respawn(){
    vida=100;
    puntos=0;
    experiencia=0;
    gotoxy(x,y);
    cout<<"Animacion de muerte"<<endl;
    system("pause");
    system("CLS");
    gotoxy(x,y);
    cout<<' ';
    x=0;y=0;//Se inicia la posicion al comienzo del nivel;
    gotoxy(x,y);
    cout<<cuerpo;
}

void personaje::desplazamiento(char tecla){
    for(int i=0;i<velocidad;i++){
    gotoxy(x,y);
    cout<<" ";

    if(tecla=='d' or tecla=='D'){
        x=x+1;
    }
    else if(tecla=='s' or tecla=='S'){
        y=y+1;
    }
    else if(tecla=='a' or tecla=='A'){
        if(x-1>=0){
        x=x-1;}
    }
    else if(tecla=='w' or tecla=='W'){
        if(y-1>=0){
        y=y-1;}
    }
    if(tecla=='f'){attack(1); vida=vida-20;}
    gotoxy(x,y);
    cout<<cuerpo;}
}

void personaje::attack(int a){
    gotoxy(x,y);
    if(a==1){
            cout<<"*";
    }
   else{
        cout<<"+";
   }

    for(int i=1;i<tipo1->getAlcance();i++){

        cout<<"-";}
    cout<<">";

    Sleep(100);
    gotoxy(x+1,y);
    for(int i=0;i<tipo1->getAlcance();i++){
        cout<<" ";}
    //condicional para ver si hay enemigos en esa pocicion
}
