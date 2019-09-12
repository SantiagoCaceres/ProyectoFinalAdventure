#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QTimer
    //signals and slots (connect function)
    //QObject and Q_OBJECT macro

    //Creamos escena
    QGraphicsScene * scene = new QGraphicsScene();

    //Crear Item para escena
    MyRect * rect = new MyRect();
    rect->setRect(0,0,100,100);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //Agregar a escena
    scene->addItem(rect);

    //Decimos que se pueda ver
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}












