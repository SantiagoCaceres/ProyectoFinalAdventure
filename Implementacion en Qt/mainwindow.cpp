#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "enemigo.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Personaje *player=new Personaje(5,5,0,0,0,0,50,3,0.08,0);
    Enemigo *play=new Enemigo(5,5,0,0,0,0,50,3,0.08,0);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    QGraphicsScene *scene=new QGraphicsScene;
    scene->addItem(player);
    player->getWeapon()->hide();
    scene->addItem(player->getWeapon());
    Players.push_back(player);
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
