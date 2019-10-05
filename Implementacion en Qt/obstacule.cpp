#include "obstacule.h"

Obstacule::Obstacule(double _PX,double _PY,double _anc,double _lar)
{
setRect(_PX,_PY,_anc,_lar);
anc=_anc;
PX=_PX;
PY=_PY;
lar=_lar;
}

void Obstacule::setPrincipal(Personaje *value)
{
    principal = value;
}

void Obstacule::colision(){

    QList<QGraphicsItem *> posterior_items =collidingItems();
    for (int i = 0, n = posterior_items.size();i<n;i++) {
        if(typeid(*(posterior_items[i])) == typeid(Personaje)){

            if(principal->getVX()>0 and principal->getPX()<PX+anc){

            }

        }
      }



}
