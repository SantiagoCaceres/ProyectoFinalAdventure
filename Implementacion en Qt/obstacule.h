#ifndef OBSTACULE_H
#define OBSTACULE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include "personaje.h"


class Obstacule:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstacule(double PX,double PY,double anc, double lar);
    ~Obstacule(){

    }
    void colision();

    void setPrincipal(Personaje *value);

private:
    double PX,PY;
    double anc,lar;
    Personaje *principal;


};

#endif // OBSTACULE_H
