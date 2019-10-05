#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "Arma.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QString>



using namespace std;

class Personaje:public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
    Personaje(int largo,int ancho,double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, double K_, double e_);
    ~Personaje(){
        delete(VIDA);

    }
    void set_vel(double velx, double vely, double px, double py);

    double getPY() const;

    double getPX() const;

    double getVX() const;

    double getVY() const;

    double getR() const;

    double getE() const;

    void setWeapon(arma *value);
    arma *getWeapon() const;
    void Damage();

    //Estadisticas
    void actualizarVIDA();

    void setVida(int value);

    int getVida() const;

    int getDefensa() const;

    void setDefensa(int value);

    int getExperiencia() const;

    void setExperiencia(int value);

    int getNivel() const;

    void setNivel(int value);

    void setName(const QString &value);



    void setJugadores(const QList<Personaje *> &value);

    QGraphicsRectItem *getVIDA() const;

    void setSaltos(int value);

protected:
    QGraphicsRectItem *VIDA=new QGraphicsRectItem(PX,PY-R*6,vida*10,2);
    QList <Personaje *> jugadores;
    arma *Weapon=new arma("Inicial",20,20,10);
    QString name="Principal";
    int vida=100,experiencia=0,defensa=10,nivel=1,velocidad=5,puntos=0,saltos=0;
    double PX;//posicion en x
        double PY;//posicion en y
        double mass;//masa del cuerpo
        double R;//radio del cuerpo
        double VX;//velocidad en x
        double VY;//velocidad en y
        double angulo;//angulo en el que va el cuerpo.
        double AX;//aceleracion en x
        double AY;//aceleracion en y
        double G;//gravedad
        double K;//resistencia del aire
        double e;//coeficiente de restitucion.
        double V;//vector velocidad.
        double dt;//delta de tiempo.

    //double posX,posY,vx0,vy0,ax,ay,vx,vy,dt=0.2;
    //double gravedad;
public slots:
    void actualizar();

};

#endif // PERSONAJE_H

/*
class personaje{
private:

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
};*/


