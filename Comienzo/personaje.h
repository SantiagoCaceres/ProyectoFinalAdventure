#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "Arma.h"

using namespace std;



class personaje{
private:
    int vida,experiencia,defensa,nivel,velocidad,puntos;
    int y=0,x=0;
    Arma *tipo1;
    char cuerpo;
public:
    personaje(int a,int b,int c,int d,int e,Arma &x,char z);
    void desplazamiento(char tecla);
    void attack();
    void estado();
    void respawn();
    void progress();//falta implementar este metodo
    void AutoLevel();//y este
};

#endif // PERSONAJE_H
