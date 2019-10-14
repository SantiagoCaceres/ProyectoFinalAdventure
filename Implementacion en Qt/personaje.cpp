#include "personaje.h"
#include "Arma.h"
#include <math.h>
#include <math.h>
#include <cmath>
#include "ascensor.h"
#include <time.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include "QDebug"
#include "QLabel"

arma *a;
item *i;
Personaje::Personaje(double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, double K_, double e_)
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
    QPixmap Pixmap(":/Images/Ghost.png");
    Pixmap=Pixmap.copy(0,32*4,32,32);
    setPixmap( Pixmap.scaled(QSize(30, 30)));
    connect(spriter,SIGNAL(timeout()),this,SLOT(sprite()));
    VIDA->show();


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


        if(PX+30>1200){//posicion con el borde derecho.
            set_vel(-1*0.2*VX,VY, 1170, PY);
        }
        if(PY+30>400){
            if(VX<0){
            set_vel(VX+0.3,-1*VY*e,PX,370);}
            else if(VX>0){
            set_vel(VX-0.3,-1*VY*e,PX,370);}

            saltos=0;


        }
        if(PY<0){
            set_vel(VX,-1*VY*e,PX,30);
        }
        if(PX<0){
            set_vel(-1*VX*e,VY,0,PY);
        }
        setPos(PX,PY);
        Weapon->setPos(PX+direccion,PY+2);Damage();
        actualizarVIDA();
        Ascender();

}

void Personaje::actualizarVIDA()
{
    VIDA->setRect(PX+5,PY-5,vida/5,2);
}

void Personaje::Items_Actuales()
{
    qDebug()<<a->getNombre();
    qDebug()<<i->getName();
}

void Personaje::Damage(){
     QList<QGraphicsItem *> colliding_items =collidingItems();
    if(name!="Principal"){
    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(Personaje)){
            if(att!=1)
            att=1;
            if(jugadores.at(0)->getAttack()==0){
            jugadores.at(0)->setVida(jugadores.at(0)->getVida()-(Weapon->getDano()/jugadores.at(0)->getDefensa()));
            jugadores.at(0)->set_vel(VX*2,jugadores.at(0)->getVY(),jugadores.at(0)->getPX(),jugadores.at(0)->getPY());}
            else{
                vida=vida-0.02*jugadores.at(0)->getWeapon()->getDano();
                if(vida<=0){
                    delete this;
                }
            }

}}

            if(jugadores.at(0)->getVida()<=0){
                jugadores.at(0)->getVIDA()->hide();
                jugadores.at(0)->setAttack(2);
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

        Weapon->setPixmap(a->pixmap());
        direccion=15;  
        }

       else if(this->collidesWithItem(i) and i->isVisible()){

           vida=vida+i->getVida();//Quitar accesorio antiguo Advertencia
           vida=vida-Accesorio->getVida();
           defensa=defensa+i->getDefensa();
           defensa=defensa-Accesorio->getDefensa();
           velocidad=velocidad+i->getVelocidad();
           velocidad=velocidad-Accesorio->getVelocidad();
           Weapon->setDano(Weapon->getDano()+i->getAtaque());
           Weapon->setDano(Weapon->getDano()-Accesorio->getAtaque());
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
    srand(time(0));
    int probabilidad;
    probabilidad=rand()%(2);
    int probabilidad3=rand()%(100);
    int probuser=jugadores.at(0)->getWeapon()->getProbabilidad();
    if (probabilidad<=2){
        QFile armas;
        armas.setFileName(":/Base/Armas.txt");
        armas.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&armas);

        if(probabilidad3<=probuser){
        int cont=0;
        int probabilidad2;
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
                   QPixmap PixmapArma(":/Images/ItemsAndWeapon.png");
                   PixmapArma=PixmapArma.copy(cont*48,150,50,50);
                   a->setPixmap(PixmapArma.scaled(30,20,Qt::KeepAspectRatioByExpanding));

                   a->setPos(PX,PY);
                   a->setPixmap( PixmapArma.scaled(QSize(30, 30)));
                   a->setPos(PX,PY);
                   scene()->addItem(a);

                   break;
               }
           }
        }
    }
    else if (probabilidad<0){
        QFile accesorios;
        accesorios.setFileName(":/Base/Items.txt");
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

                   QPixmap PixmapItem(":/Images/ItemsAndWeapon.png");
                   if(cont>=6){
                   PixmapItem=PixmapItem.copy(530,380+50*cont,50,50);}
                   else{
                       PixmapItem=PixmapItem.copy(50*cont,390+50*cont,50,50);
                   }
                   i->setPixmap(PixmapItem.scaled(30,30,Qt::KeepAspectRatioByExpanding));
                   i->setPos(PX,PY);
                   scene()->addItem(i);

                   break;
               }
           }}
    }

}

void Personaje::keyPressEvent(QKeyEvent *event){

    if(!spriter->isActive()){
    spriter->start(100);}

    if(event->key() == Qt::Key_Left){
        set_vel(-velocidad*3,VY,PX,PY);

        if(direccion!=-15){
        Weapon->setPixmap(Weapon->pixmap().transformed(QTransform().scale(-1, 1)));
        direccion=-15;}

    }
    else if (event->key() == Qt::Key_Right) {
        set_vel(velocidad*3,VY,PX,PY);

        if(direccion!=15){
        direccion=15;
        Weapon->setPixmap(Weapon->pixmap().transformed(QTransform().scale(-1, 1)));}
    }
    else if(event->key() == Qt::Key_Up and saltos<2){
        set_vel(VX,-velocidad*5,PX,PY);
        saltos++;
    }
    else if(event->key() == Qt::Key_Down){
        set_vel(0,VY+velocidad*3,PX,PY);
    }
    else if(event->key() == Qt::Key_F){
        if(att!=2){
            att=1;}
        mCurrentFrame = 0;
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

void Personaje::Ascender(){
    if(this->isVisible()){
    QList<QGraphicsItem *> Ascensor_items =collidingItems();
    for (int i = 0, n = Ascensor_items.size();i<n;i++) {
        if(typeid(*(Ascensor_items[i])) == typeid(Ascensor)){

            PY=PY-R/20;
            set_vel(VX,9.8,PX,PY);

            if(VY<0){
                PY=PY-R/20;
                set_vel(VX,VY*0,PX,PY);


                }
            if(VY>0){
                PY=PY-R/20;
                set_vel(VX,-VY*e,PX,PY);

            }

            if(VX<0){
                PY=PY-R/20;
                set_vel(VX+0.3,VY*0,PX,PY);


                }
            if(VX>0){
                PY=PY-R/20;
                set_vel(VX-0.3,-VY*e,PX,PY);

            }
            saltos=0;
        }
      }
    }
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

int Personaje::getAttack() const
{
    return att;
}

void Personaje::setAttack(int value)
{
    att = value;
}

void Personaje::sprite(){

        if(name=="Principal"){
            mCurrentFrame += 32;
                if (mCurrentFrame >= 320 ){
                    if(att==1){
                        att=0;
                    }
                    else if(att==2){
                        hide();
                        VIDA->hide();
                    }
                    mCurrentFrame = 0;}
        QPixmap mover(":/Images/Ghost.png");
        if(att==1){
            mover=mover.copy(mCurrentFrame,32*3,32,32);
            if(direccion<0){mover = mover.transformed(QTransform().scale(-1, 1));}

        }
        else if(att==2){
            mover=mover.copy(mCurrentFrame,32*4,32,32);
            if(direccion<0){mover = mover.transformed(QTransform().scale(-1, 1));}
        }
        else if(VX<1 and VX>-1){
            if(direccion<0){
                 mover = mover.transformed(QTransform().scale(-1, 1));
            }
            mover=mover.copy(mCurrentFrame,32*2,32,32);
            mCurrentFrame=0;

        }
        else if(VX<0){
            mover = mover.transformed(QTransform().scale(-1, 1));
            mover=mover.copy(mCurrentFrame,32*2,32,32);

        }
        else if(VX>0){
            mover=mover.copy(mCurrentFrame,32*2,32,32);
        }
        setPixmap(mover.scaled(30,30,Qt::KeepAspectRatio));
        }
        else{
            if(att!=1){
            mCurrentFrame += 22;
                if (mCurrentFrame >= 286 ){

                    mCurrentFrame = 0;}}
            else{

                mCurrentFrame += 43;
                    if (mCurrentFrame >= 774 ){
                        mCurrentFrame = 0;
                        att=0;
                    }
            }

            QPixmap mover(":/Images/Skeleton Walk.png");
            QPixmap ataque(":/Images/Skeleton Attack.png");

            mover=mover.copy(mCurrentFrame,0,22,33);

            if(att==1){

                ataque=ataque.copy(mCurrentFrame,0,43,37);
                if(PX>jugadores.at(0)->getPX()){mover = mover.transformed(QTransform().scale(-1, 1));}

            }
            else if(VX<1 and VX>-1){


                mover = mover.transformed(QTransform().scale(-1, 1));


                mCurrentFrame=0;

            }
            else if(VX<0){
                mover = mover.transformed(QTransform().scale(-1, 1));

            }
            if(att!=1){
            setPixmap(mover.scaled(30,30,Qt::KeepAspectRatio));}
            else{
                setPixmap(ataque.scaled(33,40,Qt::KeepAspectRatio));
            }

    }
}

