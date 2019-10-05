#ifndef LATERAL_H
#define LATERAL_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Lateral:public QObject, public QGraphicsRectItem
{   Q_OBJECT
public:
    Lateral();
    ~Lateral(){
    }
};

#endif // LATERAL_H
