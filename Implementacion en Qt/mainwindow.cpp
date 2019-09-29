#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "enemigo.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Personaje *player=new Personaje(5,5,0,0,0,0,50,3,0.08,0.6);
    Enemigo *play=new Enemigo(5,5,0,0,0,0,50,3,0.08,0);
    play->setName("enemigo");
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    QGraphicsScene *scene=new QGraphicsScene;
    scene->addItem(player);
    player->getWeapon()->hide();
    scene->addItem(player->getVIDA());
    player->getVIDA()->show();
    scene->addItem(play->getVIDA());
    play->getVIDA()->show();
    scene->addItem(player->getWeapon());
    Players.push_back(player);
    play->setJugadores(Players);
    scene->addItem(play);
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
