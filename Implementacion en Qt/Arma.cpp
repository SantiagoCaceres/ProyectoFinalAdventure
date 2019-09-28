#include "arma.h"
#include "enemigo.h"
arma::arma()
{
    setRect(0,0,20,5);
    //Conexion
}

void arma::Delete(){
    this->hide();

}

void arma::move(){
    if(this->isVisible()){
    QList<QGraphicsItem *> colliding_items =collidingItems();
    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(Enemigo)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }}


}
