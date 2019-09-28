#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cuerpo.h"
#include <QGraphicsScene>
#include <QList>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Cuerpo *player=new Cuerpo(5,5,0,0,0,0,50,3,2.5,5);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsScene *scene=new QGraphicsScene;
    a.push_back(player);
    scene->addItem(player);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,600);
    ui->graphicsView->setSceneRect(0,0,800,600);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
    ui->centralWidget->adjustSize();
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QTimer *timer=new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(limites()));
    timer->start(20);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::limites()
{
    if(a.at(0)->getPY()>600-a.at(0)->getR()){
        a.at(0)->set_vel(a.at(0)->getVX(),-9.8*a.at(0)->getE(),a.at(0)->getPX(),a.at(0)->getPY()-a.at(0)->getR());
    }

}
