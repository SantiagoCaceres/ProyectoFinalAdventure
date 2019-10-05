#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "enemigo.h"
#include "list"
#include "suelo.h"
#include "lateral.h"
#include "posterior.h"
#include "inferior.h"
#include "asensor.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    list <Enemigo *> enemigos;
    Personaje *player=new Personaje(5,5,0,0,0,0,50,3,0.08,0);
    Suelo *earth=new Suelo;
    Posterior *izquierda=new Posterior;
    Lateral *derecho=new Lateral;
    Inferior *bajo=new Inferior;
    Asensor *up=new Asensor;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();    
    scene->addItem(player);
    scene->addItem(earth);
    scene->addItem(izquierda);
    scene->addItem(derecho);
    scene->addItem(up);
    scene->addItem(bajo);
    player->getWeapon()->hide();
    scene->addItem(player->getVIDA());
    player->getVIDA()->show();
    scene->addItem(player->getWeapon());

    Players.push_back(player);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(1200,400);
    ui->graphicsView->setSceneRect(0,0,1200,400);
    ui->graphicsView->resize(int(scene->width()),int(scene->height()));
    ui->centralWidget->adjustSize();
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



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
