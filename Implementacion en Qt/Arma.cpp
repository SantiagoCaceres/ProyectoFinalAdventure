#include "arma.h"
#include "enemigo.h"
arma::arma(QString _nombre,int _Dano,int _Alcance,int _Probabilidad)
{
    setRect(0,0,20,5);
    nombre=_nombre;
    dano=_Dano;
    alcance=_Alcance;
    probabilidad=_Probabilidad;
}

void arma::Delete(){
    this->hide();

}

int arma::getProbabilidad() const
{
    return probabilidad;
}

int arma::getAlcance() const
{
    return alcance;
}

int arma::getDano() const
{
    return dano;
}


