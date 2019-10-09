#ifndef ARMA_H
#define ARMA_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QString>

class arma: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    arma(QString _nombre,int _Dano,int _Alcance,int _Probabilidad);

    int getDano() const;

    int getAlcance() const;

    int getProbabilidad() const;

    void setDano(int value);

    void setAlcance(int value);

    void setProbabilidad(int value);

    void setNombre(const QString &value);

    QString getNombre() const;

public slots:
    void Delete();
private:
    QString nombre;
    int dano,alcance,probabilidad;
};

#endif // ARMA_H
