#ifndef ITEM_H
#define ITEM_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QString>
using namespace std;


class item: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QString name;
    int vida=0;
    int defensa=0;
    int velocidad=0;
    int ataque=0;
public:
    item(QString,int,int,int,int);
    ~item(){
    }


    void setName(const QString &value);
    void setVida(int value);
    void setDefensa(int value);
    void setVelocidad(int value);
    void setAtaque(int value);
    QString getName() const;
    int getVida() const;
    int getDefensa() const;
    int getVelocidad() const;
    int getAtaque() const;
public slots:
    void Delete();
};

#endif // ITEM_H
