#include "arma.h"
#include "enemigo.h"
arma::arma(QString _nombre,int _Dano,int _Alcance,int _Probabilidad)
{
    setRect(0,0,50,5);
    nombre=_nombre;
    dano=_Dano;
    alcance=_Alcance;
    probabilidad=_Probabilidad;
}

void arma::Delete(){
    this->hide();

}

QString arma::getNombre() const
{
    return nombre;
}

void arma::setNombre(const QString &value)
{
    nombre = value;
}

void arma::setProbabilidad(int value)
{
    probabilidad = value;
}

void arma::setAlcance(int value)
{
    alcance = value;
}

void arma::setDano(int value)
{
    dano = value;
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


