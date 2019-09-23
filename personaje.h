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
    char cuerpo;
protected:
     Arma *tipo1;
public:
    personaje(int a,int b,int c,int d,int e,Arma &x,char z);
    void desplazamiento(char tecla);
    void attack(int a, char b);
    int estado();
    void respawn();
    void progress();//falta implementar este metodo
    void AutoLevel();//y este
    void setY(int value);
    void setX(int value);
    int getY() const;
    int getX() const;
    char getCuerpo() const;
    void setVida(int value);
    int getVida() const;
    Arma *getTipo1() const;
    int getExperiencia() const;
    int getDefensa() const;
    int getNivel() const;
    int getVelocidad() const;
    int getPuntos() const;
    void setExperiencia(int value);
    void setDefensa(int value);
    void setNivel(int value);
    void setVelocidad(int value);
    void setPuntos(int value);
    void setCuerpo(char value);
    void setTipo1(Arma *value);
};

#endif // PERSONAJE_H
