#ifndef ENEMIGO_H
#define ENEMIGO_H



#include "personaje.h"
#include<time.h>
#include<stdlib.h>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class Enemigo:public Personaje
{
    Q_OBJECT
public:
    Enemigo(int largo,int ancho,double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, double K_, double e_);
public slots:
    void move();
    //void user_attack();
};
#endif // ENEMIGO_H
