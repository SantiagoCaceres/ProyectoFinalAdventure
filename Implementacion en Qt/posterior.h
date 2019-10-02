#ifndef POSTERIOR_H
#define POSTERIOR_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Posterior:public QObject, public QGraphicsRectItem
{   Q_OBJECT
public:
    Posterior();
    ~Posterior(){
    }
};

#endif // POSTERIOR_H
