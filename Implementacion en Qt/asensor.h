#ifndef ASENSOR_H
#define ASENSOR_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Asensor:public QObject, public QGraphicsRectItem
{   Q_OBJECT
public:
    Asensor();
    ~Asensor(){

    }
};

#endif // ASENSOR_H
