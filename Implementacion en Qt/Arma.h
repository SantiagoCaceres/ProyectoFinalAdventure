#ifndef ARMA_H
#define ARMA_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include <QList>

class arma: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    arma();

public slots:
    void move();
    void Delete();
};

#endif // ARMA_H
