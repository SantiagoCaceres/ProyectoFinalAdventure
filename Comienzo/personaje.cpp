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

personaje::personaje(int a,int b,int c,int d,int e,Arma &x,char z){
    vida=a;
    experiencia=b;
    defensa=c;
    nivel=d;
    velocidad=e;
    tipo1=&x;
    cuerpo=z;
}

void personaje::estado(){
    if(vida<=0){
        cout<<"Acabas de morir"<<endl;//desplegar mensaje si es el personaje del usuario
        system("pause");
        system("CLS");
        respawn();
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
    gotoxy(x,y);
    cout<<" ";
    if(tecla=='d' or tecla=='D'){
        x=x+velocidad;
    }
    else if(tecla=='s' or tecla=='S'){
        y=y+velocidad;
    }
    else if(tecla=='a' or tecla=='A'){
        if(x-velocidad>=0){
        x=x-velocidad;}
    }
    else if(tecla=='w' or tecla=='W'){
        if(y-velocidad>=0){
        y=y-velocidad;}
    }
    if(tecla=='f'){attack(); vida=vida-20;}
    gotoxy(x,y);
    cout<<cuerpo;
}

void personaje::attack(){
    gotoxy(x,y);
    cout<<"*---->";
    Sleep(100);
    gotoxy(x,y);
    cout<<"      ";
    //condicional para ver si hay enemigos en esa pocicion
}
