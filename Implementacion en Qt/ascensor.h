#ifndef ASCENSOR_H
#define ASCENSOR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Ascensor:public QObject, public QGraphicsPixmapItem
{   Q_OBJECT
public:
    Ascensor(int posx,int posy,int anc,int lar);
    ~Ascensor(){

    }
};

#endif // Ascensor_H
