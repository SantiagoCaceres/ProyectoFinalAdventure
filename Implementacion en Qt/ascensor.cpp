#include "ascensor.h"

Ascensor::Ascensor(int posx,int posy,int anc,int lar)
{
    QPixmap ascensor(":/Images/Elevator.png");
    ascensor=ascensor.scaled(QSize(anc,lar),Qt::KeepAspectRatioByExpanding);
    setPixmap(ascensor);
    setPos(posx,posy);
}
