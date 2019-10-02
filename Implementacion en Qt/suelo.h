#ifndef SUELO_H
#define SUELO_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Suelo: public QObject, public QGraphicsRectItem
{   Q_OBJECT
public:
    Suelo();
    ~Suelo(){
    }
};

#endif // SUELO_H
