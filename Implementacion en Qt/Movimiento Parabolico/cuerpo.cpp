#include "cuerpo.h"
#include <math.h>
#include <cmath>



Cuerpo::Cuerpo(int largo,int ancho,double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, double K_, double e_)
{

    PX = posX_;
    PY = posY_;
    mass = masa_;
    R = radio_;
    VX = velX_;
    VY = velY_;
    AX = 0;
    AY = 0;
    G = 9.8;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;
    setRect(posX_,posY_,largo,ancho);
    setScale(3);
    QTimer *timer=new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(10);
}

void Cuerpo::set_vel(double velx, double vely, double px, double py)
{

    VX = velx;
    VY = vely;
    PX = px;
    PY = py;

    /*posX=_posX;
    posY=_posY;
    vx0=_vx0;
    vy0=_vy0;
    gravedad=9.8;*/
}

void Cuerpo::actualizar()
{

    V = pow(((VX*VX)+(VY*VY)),1/2);
        angulo = atan2(VY,VX);
        AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);
        AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))+G;
        PX = PX + (VX*dt) +((AX*(dt*dt))/2);
        PY = PY + (VY*dt) +((AY*(dt*dt))/2);
        VX = VX + AX*dt;
        VY = VY + AY*dt;
        setPos(PX,PY);}

void Cuerpo::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        set_vel(-50,VY,PX,PY);
    }
    else if (event->key() == Qt::Key_Right) {
        set_vel(50,VY,PX,PY);
    }
    else if(event->key() == Qt::Key_Up){
        set_vel(VX,-50,PX,PY);
    }


}

double Cuerpo::getPY() const
{
    return PY;
}

double Cuerpo::getPX() const
{
    return PX;
}

double Cuerpo::getVX() const
{
    return VX;
}

double Cuerpo::getVY() const
{
    return VY;
}

double Cuerpo::getR() const
{
    return R;
}

double Cuerpo::getE() const
{
    return e;
}
