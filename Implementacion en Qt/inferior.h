#ifndef INFERIOR_H
#define INFERIOR_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Inferior:public QObject, public QGraphicsRectItem
{ Q_OBJECT
public:
    Inferior();
    ~Inferior(){

    }
};

#endif // INFERIOR_H
