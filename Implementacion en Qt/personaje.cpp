#include "personaje.h"
#include "Arma.h"
#include <math.h>
#include <math.h>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include "QDebug"

arma *a;
item *i;
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
     QList<QGraphicsItem *> colliding_items =collidingItems();
    if(name!="Principal"){
    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(arma) and this->collidesWithItem(jugadores.at(0)->getWeapon())){
            vida=vida-0.01*jugadores.at(0)->getWeapon()->getDano();
            if(vida<=0){
                Drop();
                scene()->removeItem(this);
                delete this;
            }

        }
        else if(typeid(*(colliding_items[i])) == typeid(Personaje)){
            jugadores.at(0)->setVida(jugadores.at(0)->getVida()-(Weapon->getDano()/jugadores.at(0)->getDefensa()));
            if(PX<jugadores.at(0)->getPX()){
            jugadores.at(0)->set_vel(VX*2,jugadores.at(0)->getVY(),jugadores.at(0)->getPX(),jugadores.at(0)->getPY());
}
            else{
                jugadores.at(0)->set_vel(-VX*2,jugadores.at(0)->getVY(),PX-R*4,jugadores.at(0)->getPY());
            }

            }

            if(jugadores.at(0)->getVida()<=0){
                scene()->removeItem(jugadores.at(0)->getVIDA());
                scene()->removeItem(jugadores.at(0));
            }
        }
        return;
    }

    else{

       if(this->collidesWithItem(a) and a->isVisible()){

        setWeapon(a);
        QTimer *f=new QTimer;
        connect(f,SIGNAL(timeout()),a,SLOT(Delete()));
        f->setSingleShot(true);
        f->start(500);


        Weapon->setRect(0,0,20,10);



        }

       else if(this->collidesWithItem(i) and i->isVisible()){
           vida=vida+i->getVida();//Quitar accesorio antiguo Advertencia
           defensa=defensa+i->getDefensa();
           velocidad=velocidad+i->getVelocidad();
           Weapon->setDano(Weapon->getDano()+i->getAtaque());

           setAccesorio(i);
           QTimer *f=new QTimer;
           connect(f,SIGNAL(timeout()),i,SLOT(Delete()));
           f->setSingleShot(true);
           f->start(500);





           }




    }
}


void Personaje::Drop()
{
    srand(time(NULL));
    int probabilidad;
    probabilidad=rand()%(2);
    srand(time(NULL));
    int probabilidad3=rand()%(100);
    int probuser=jugadores.at(0)->getWeapon()->getProbabilidad();
    if (probabilidad<=0){
        QFile armas;
        armas.setFileName("C:/Users/santy/Desktop/Obstacule_Branch/ProyectoFinalAdventure/Implementacion en Qt/Armas.txt");
        armas.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&armas);

        if(probabilidad3<=probuser){
        int cont=0;
        int probabilidad2;
        srand(time(NULL));
        probabilidad2=rand()%(21);
        while (!in.atEnd()) {
               QString line = in.readLine();
               cont++;
               if(cont==probabilidad2){
                   QStringList list1 = line.split(',');
                   QString nombre=list1.at(0);
                   int dano,alcance,prob;
                   dano=list1.at(1).toInt();
                   alcance=list1.at(2).toInt();
                   prob=list1.at(3).toInt();

                   a=new arma(nombre,dano,alcance,prob);
                   a->setPos(PX,PY);
                   a->setRect(0,0,5,5);
                   scene()->addItem(a);
                   break;
               }
           }}
    }
    else if (probabilidad==1){
        QFile accesorios;
        accesorios.setFileName("C:/Users/santy/Desktop/Obstacule_Branch/ProyectoFinalAdventure/Implementacion en Qt/Items.txt");
        accesorios.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&accesorios);
        if(probabilidad3<=probuser){
        int cont=0;
        int probabilidad2;
        srand(time(NULL));
        probabilidad2=rand()%(8);
        while (!in.atEnd()) {
               QString line = in.readLine();
               cont++;
               if(cont==probabilidad2){
                   QStringList list1 = line.split(',');
                   QString nombre=list1.at(0);
                   int life,defense,speed,attack;
                   life=list1.at(1).toInt();
                   defense=list1.at(2).toInt();
                   speed=list1.at(3).toInt();
                   attack=list1.at(4).toInt();
                   i=new item(nombre,life,defense,speed,attack);
                   i->setPos(PX,PY);
                   i->setRect(0,0,1,5);

                   scene()->addItem(i);
                   break;
               }
           }}

    }
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
 Weapon->setNombre(value->getNombre());
 Weapon->setDano(value->getDano());
 Weapon->setAlcance(value->getAlcance());
 Weapon->setProbabilidad(value->getProbabilidad());
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

void Personaje::setSaltos(int value)
{
    saltos = value;
}

void Personaje::setAccesorio(item *value)
{
    Accesorio->setName(value->getName());
    Accesorio->setVida(value->getVida());
    Accesorio->setDefensa(value->getDefensa());
    Accesorio->setVelocidad(value->getVelocidad());
    Accesorio->setAtaque(value->getAtaque());

}

item *Personaje::getAccesorio() const
{
    return Accesorio;
}


