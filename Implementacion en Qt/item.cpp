#include "item.h"

void item::Delete(){
    this->hide();

}
void item::setName(const QString &value)
{
    name = value;
}

void item::setVida(int value)
{
    vida = value;
}

void item::setDefensa(int value)
{
    defensa = value;
}

void item::setVelocidad(int value)
{
    velocidad = value;
}

void item::setAtaque(int value)
{
    ataque = value;
}

QString item::getName() const
{
    return name;
}

int item::getVida() const
{
    return vida;
}

int item::getDefensa() const
{
    return defensa;
}

int item::getVelocidad() const
{
    return velocidad;
}

int item::getAtaque() const
{
    return ataque;
}

item::item(QString _nombre, int _vida, int _defensa, int _velocidad, int _ataque)
{
    name=_nombre;
    vida=_vida;
    defensa=_defensa;
    velocidad=_velocidad;
    ataque=_ataque;
}


