#ifndef CUERPO_H
#define CUERPO_H
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QTimer>

class Cuerpo:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Cuerpo(int largo,int ancho,double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, double K_, double e_);
    ~Cuerpo(){

    }
    void set_vel(double velx, double vely, double px, double py);
    void keyPressEvent(QKeyEvent * event);

    double getPY() const;

    double getPX() const;

    double getVX() const;

    double getVY() const;

    double getR() const;

    double getE() const;

private:
    double PX;//posicion en x
        double PY;//posicion en y
        double mass;//masa del cuerpo
        double R;//radio del cuerpo
        double VX;//velocidad en x
        double VY;//velocidad en y
        double angulo;//angulo en el que va el cuerpo.
        double AX;//aceleracion en x
        double AY;//aceleracion en y
        double G;//gravedad
        double K;//resistencia del aire
        double e;//coeficiente de restitucion.
        double V;//vector velocidad.
        double dt;//delta de tiempo.

    //double posX,posY,vx0,vy0,ax,ay,vx,vy,dt=0.2;
    //double gravedad;
public slots:
    void actualizar();
};

#endif // CUERPO_H
