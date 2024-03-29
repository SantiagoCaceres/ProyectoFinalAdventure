#ifndef ARMA_H
#define ARMA_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QString>

class arma: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    arma(QString _nombre,int _Dano,int _Alcance,int _Probabilidad);

    int getDano() const;

    int getAlcance() const;

    int getProbabilidad() const;

public slots:
    void Delete();
private:
    QString nombre;
    int dano,alcance,probabilidad;
};

#endif // ARMA_H
