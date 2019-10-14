#include "mainwindow.h"
#include <personaje.h>
#include <enemigo.h>
#include <QTimer>
#include <QApplication>
#include <QGraphicsView>
#include "QFileDialog"
#include "QGraphicsScene"
#include "login.h"
#include <QDebug>


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;

    return a.exec();

}
