#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "enemigo.h"
#include "list"
#include "asensor.h"
#include <QDebug>
#include <obstacule.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    list <Enemigo *> enemigos;
    Personaje *player=new Personaje(5,5,0,0,0,0,50,3,0.08,0);
    Asensor *up=new Asensor;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    scene->addItem(up);
    player->getWeapon()->hide();
    scene->addItem(player->getVIDA());
    player->getVIDA()->show();
    scene->addItem(player->getWeapon());
    Obstacule *uno=new Obstacule(100,350,100,20);
    scene->addItem(uno);
    Obstaculos.push_back(uno);

    Players.push_back(player);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(1000,400);
    ui->graphicsView->setSceneRect(0,0,3000,400);
    ui->graphicsView->resize(int(scene->width()),int(scene->height()));
    ui->centralWidget->adjustSize();
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QTimer *timm=new QTimer;
    connect(timm,SIGNAL(timeout()),this,SLOT(actualizarmapa()));
    timm->start(10);

    show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Enemigo *play=new Enemigo(5,5,0,0,0,0,50,3,0.08,0);

    play->setName("enemigo");//
    play->getVIDA()->show();//
    play->setJugadores(Players);
    scene->addItem(play);
    scene->addItem(play->getVIDA());


}

void MainWindow::actualizarmapa()
{
        Players.at(0)->actualizar();
        Obstaculos.at(0)->setPrincipal(Players.at(0));
        Obstaculos.at(0)->colision();
        ui->graphicsView->setSceneRect(Players.at(0)->getPX(),0,50,400);
        qDebug()<<Players.at(0)->getPX();

}
