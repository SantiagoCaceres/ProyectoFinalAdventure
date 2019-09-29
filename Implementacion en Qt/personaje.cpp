#include "personaje.h"
#include "Arma.h"
#include <math.h>
#include <math.h>
#include <cmath>



Personaje::Personaje(int largo,int ancho,double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, double K_, double e_)
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
    VIDA->show();
    setScale(2);
    QTimer *timer=new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(10);
}

void Personaje::set_vel(double velx, double vely, double px, double py)
{

    VX = velx;
    VY = vely;
    PX = px;
    PY = py;

}

void Personaje::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),1/2);
        angulo = atan2(VY,VX);
        AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);
        AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))+G;
        PX = PX + (VX*dt) +((AX*(dt*dt))/2);
        PY = PY + (VY*dt) +((AY*(dt*dt))/2);
        VX = VX + AX*dt;
        VY = VY + AY*dt;


        if(PX>1200-R*6){//posicion con el borde derecho.
            set_vel(-1*0.2*VX,VY, 1200-R*6, PY);
        }
        if(PY>400-R*6){
            if(VX<0){
            set_vel(VX+0.3,-1*VY*e,PX,400-R*6);}
            else if(VX>0){
            set_vel(VX-0.3,-1*VY*e,PX,400-R*6);}

            saltos=0;


        }
        if(PY<R){
            set_vel(VX,-1*VY*e,PX,R);
        }
        if(PX<R){
            set_vel(-1*VX*e,VY,R,PY);
        }
        setPos(PX,PY);
        Weapon->setPos(PX,PY);Damage();
                actualizarVIDA();




}

void Personaje::actualizarVIDA()
{
    VIDA->setRect(PX-5,PY-R*3,vida/5,2);
}

void Personaje::Damage(){
    if(name!="Principal"){
    QList<QGraphicsItem *> colliding_items =collidingItems();
    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(arma)){
            vida=vida-0.01*jugadores.at(0)->getWeapon()->getDano();
            if(vida<=0){

                scene()->removeItem(this);
                delete this;
            }
            return;
        }
    }}
}

void Personaje::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        set_vel(-velocidad*3,VY,PX,PY);
    }
    else if (event->key() == Qt::Key_Right) {
        set_vel(velocidad*3,VY,PX,PY);
    }
    else if(event->key() == Qt::Key_Up and saltos<2){
        set_vel(VX,-velocidad*5,PX,PY);
        saltos++;
    }
    else if(event->key() == Qt::Key_Down){
        set_vel(0,VY+velocidad*3,PX,PY);
    }
    else if(event->key() == Qt::Key_F){
        Weapon->show();
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),Weapon,SLOT(Delete()));
        timer->setSingleShot(true);
        timer->start(500);
    }

}

double Personaje::getPY() const
{
    return PY;
}

double Personaje::getPX() const
{
    return PX;
}

double Personaje::getVX() const
{
    return VX;
}

double Personaje::getVY() const
{
    return VY;
}

double Personaje::getR() const
{
    return R;
}

double Personaje::getE() const
{
    return e;
}

void Personaje::setWeapon(arma *value)
{
    Weapon = value;
}

arma *Personaje::getWeapon() const
{
    return Weapon;
}

void Personaje::setVida(int value)
{
    vida = value;
}

int Personaje::getVida() const
{
    return vida;
}

int Personaje::getDefensa() const
{
    return defensa;
}

void Personaje::setDefensa(int value)
{
    defensa = value;
}

int Personaje::getExperiencia() const
{
    return experiencia;
}

void Personaje::setExperiencia(int value)
{
    experiencia = value;
}

int Personaje::getNivel() const
{
    return nivel;
}

void Personaje::setNivel(int value)
{
    nivel = value;
}

void Personaje::setName(const QString &value)
{
    name = value;
}

void Personaje::setJugadores(const QList<Personaje *> &value)
{
    jugadores = value;
}

QGraphicsRectItem *Personaje::getVIDA() const
{
    return VIDA;
}


