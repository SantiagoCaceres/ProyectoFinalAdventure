#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "enemigo.h"
#include "list"
#include <QDebug>
#include "QFileDialog"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    list <Enemigo *> enemigos;
    Personaje *player=new Personaje(5,5,0,300,0,0,50,3,0.08,0);
    player->setPos(100,100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    player->getWeapon()->hide();
    scene->addItem(player->getVIDA());
    player->getVIDA()->show();
    scene->addItem(player->getWeapon());


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
    Enemigo *play=new Enemigo(10,10,0,0,50,0,50,3,0.08,0);

    play->setName("enemigo");//
    play->getVIDA()->show();//
    play->setJugadores(Players);
    scene->addItem(play);
    scene->addItem(play->getVIDA());


}

void MainWindow::actualizarmapa()
{
        Players.at(0)->actualizar();
        ui->graphicsView->setSceneRect(Players.at(0)->getPX(),0,50,400);
        //qDebug()<<Players.at(0)->getPX();

}
