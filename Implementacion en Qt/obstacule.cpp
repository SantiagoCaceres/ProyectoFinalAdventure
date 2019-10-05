#include "obstacule.h"

Obstacule::Obstacule(double PX,double PY,double anc,double lar)
{
setRect(PX,PY,anc,lar);
}

void Obstacule::setPrincipal(Personaje *value)
{
    principal = value;
}

void Obstacule::colision(){



}
