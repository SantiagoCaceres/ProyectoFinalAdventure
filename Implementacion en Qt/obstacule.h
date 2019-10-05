#ifndef OBSTACULE_H
#define OBSTACULE_H
#include <QGraphicsRectItem>
#include <QObject>
#include "personaje.h"


class Obstacule:public QObject, public QGraphicsRectItem
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
    Personaje *principal;

};

#endif // OBSTACULE_H
