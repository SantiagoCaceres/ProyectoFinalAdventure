#include "mainwindow.h"
#include <personaje.h>
#include <enemigo.h>
#include <QTimer>
#include <QApplication>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
