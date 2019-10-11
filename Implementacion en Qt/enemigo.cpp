#include "enemigo.h"
#include <time.h>



Enemigo::Enemigo(int largo,int ancho,double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, double K_, double e_):Personaje (posX_,posY_, velX_, velY_, masa_, radio_, K_, e_)
{
QTimer *a=new QTimer;
QTimer *b=new QTimer;
QPixmap Pixmap(":/Images/bad");
setPixmap( Pixmap.scaled(QSize(30, 30)));
QObject::connect(a,SIGNAL(timeout()),this,SLOT(actualizar()));
a->start(10);
QObject::connect(b,SIGNAL(timeout()),this,SLOT(move()));
b->start(1000);
}


void Enemigo::move(){
    srand(time(NULL));
    int random_number = 1+rand()%(3-1);
    if(random_number==1){
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
