#include "enemigo.h"
#include <time.h>



Enemigo::Enemigo(int largo,int ancho,double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, double K_, double e_):Personaje (posX_,posY_, velX_, velY_, masa_, radio_, K_, e_)
{
QTimer *a=new QTimer;
QTimer *b=new QTimer;
QPixmap Pixmap(":/Images/Skeleton Walk.png");
Pixmap=Pixmap.copy(0,0,22,33);
setPixmap( Pixmap.scaled(QSize(30, 30),Qt::KeepAspectRatio));
QObject::connect(a,SIGNAL(timeout()),this,SLOT(actualizar()));
a->start(10);
QObject::connect(b,SIGNAL(timeout()),this,SLOT(move()));
b->start(1000);
spriter->start(100);
}


void Enemigo::move(){
    srand(time(0));
    int random_number =6;
    random_number=rand()%(random_number);
    if(random_number<3){
    set_vel(VX+15,VY,PX,PY);}
    else{
    set_vel(VX-15,VY,PX,PY);}

    if(pos().x()> 1200){
        scene()->removeItem(this);
        delete this;
    }
    else  if(pos().x()  < 0){
        scene()->removeItem(this);
        delete this;
    }

}
