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
        if(principal->getVX()>0 and principal->getPY()>PY and principal->getPY()<PY+lar and principal->getPX()<PX){
        principal->set_vel(-principal->getVX()*0.2,principal->getVY(),PX-25,principal->getPY());
        }
        else if(principal->getVX()<0 and principal->getPY()>PY and principal->getPY()<PY+lar and PX+anc<principal->getPX()){
            principal->set_vel(-principal->getVX()*0.2,principal->getVY(),PX+anc+30,principal->getPY());
            }
        else if(principal->getVY()>0 and principal->getPX()>PX and principal->getPX()<PX+anc){

            principal->set_vel(principal->getVX(),9.8,principal->getPX(),PY-25);
            }
        else if(principal->getVY()<0 and principal->getPX()>PX and principal->getPX()<PX+anc){

            principal->set_vel(principal->getVX(),-principal->getVY()*0.2,principal->getPX(),PY+lar);

            }


           principal->setSaltos(0);


        }
      }



}
