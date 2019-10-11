#include "obstacule.h"
#include <QDebug>
Obstacule::Obstacule(double _PX,double _PY,double _anc,double _lar)
{

QPixmap plataforma(":/Images/Plataforma3.png");
plataforma=plataforma.scaled(QSize(int(_anc),int(_lar)),Qt::KeepAspectRatioByExpanding);
setPixmap(plataforma);
anc=_anc;
PX=_PX;
PY=_PY;
lar=_lar;
setPos(PX,PY);
}

void Obstacule::setPrincipal(Personaje *value)
{
    principal = value;
}

void Obstacule::colision(){

    QList<QGraphicsItem *> posterior_items =collidingItems();
    for (int i = 0, n = posterior_items.size();i<n;i++) {
        if(typeid(*(posterior_items[i])) == typeid(Personaje)){
        if(principal->getVY()>0 and principal->getPY()<PY and principal->getPX()<PX+anc and principal->getPX()>PX){

        principal->set_vel(principal->getVX(),9.8,principal->getPX(),PY-25);
        }



           principal->setSaltos(0);


        }
      }



}
