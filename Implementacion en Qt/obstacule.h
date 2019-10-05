#ifndef OBSTACULE_H
#define OBSTACULE_H
#include <QGraphicsRectItem>
#include <QObject>


class Obstacule:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Obstacule();
    ~Obstacule(){

    }
    void colision();
};

#endif // OBSTACULE_H
