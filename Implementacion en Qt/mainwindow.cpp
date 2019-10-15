#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "enemigo.h"
#include "list"
#include "ascensor.h"
#include <QDebug>
#include "QFileDialog"
#include <QSerialPortInfo>
#include <obstacule.h>
#include "login.h"
#include "menu.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;


    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug()<<"Vendor id "<<serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug()<<"Vendor ID"<<serialPortInfo.hasVendorIdentifier();
        }
        qDebug()<<"Product id"<<serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug()<<"Product ID"<<serialPortInfo.hasProductIdentifier();
        }
    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available){
        // open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
            qDebug()<<"Arduino no encontrado";
    }

        a = new Login(this);
        a->show();
        connect(timerr,SIGNAL(timeout()),this,SLOT(verificar()));
        connect(timerr,SIGNAL(timeout()),this,SLOT(menu));
        //connect(timerr,S)
        timerr->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarmapa()
{
    int cont=0;

        Players.at(0)->actualizar();
        for(int i=0;i<Obstaculos.size();i++){
            Obstaculos[i]->setPrincipal(Players.at(0));
            Obstaculos[i]->colision();
        }
        ui->graphicsView->setSceneRect(Players.at(0)->getPX(),0,50,400);
        for(int i=0;i<enemigos.size();i++){
            if(!enemigos.at(i)->isVisible()){
                cont++;
            }
        }
        if(cont==enemigos.size()){
            cambiar_nivel();
            Players.at(0)->setPX(0);
            Players.at(0)->setPY(0);

        }
        //qDebug()<<Players.at(0)->getPX();

}


void MainWindow::verificar(){
     t=a->getEntrada();
    if(t==true){
        a->close();
        timerr->stop();


        ui->setupUi(this);
        Personaje *player=new Personaje(300,100,0,0,50,3,0.08,0);
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
        QPixmap fondo(":/Images/BackGround.png");
        fondo=fondo.scaled(QSize(1000,400),Qt::KeepAspectRatioByExpanding);
        ui->graphicsView-> setBackgroundBrush(QBrush(fondo));
        cambiar_nivel();
        QTimer *timm=new QTimer;
        connect(timm,SIGNAL(timeout()),this,SLOT(actualizarmapa()));
        timm->start(10);
        show();
        QTimer *puntos=new QTimer;
        connect(puntos,SIGNAL(timeout()),this,SLOT(puntos()));
        puntos->start(3000);

    }
}
void MainWindow::menu(){

}
void MainWindow::cambiar_nivel(){
    for(int i=0;i<enemigos.size();i++){
        scene->removeItem(enemigos[i]);
    }
    for(int i=0;i<Obstaculos.size();i++){
        scene->removeItem(Obstaculos[i]);
    }
    for(int i=0;i<Ascensores.size();i++){
        scene->removeItem(Ascensores[i]);
    }
enemigos.clear();
Obstaculos.clear();
Ascensores.clear();
QString Posiciones,PosicionX,PosicionY;
QFile Niveles;
Niveles.setFileName(":/Base/Niveles.txt");
Niveles.open(QIODevice::ReadOnly);
int cont=1;

while (!Niveles.atEnd()) {
Posiciones=Niveles.readLine();

if(Posiciones!="{\r\n" and Posiciones!="}\r\n"){
QStringList Pos=Posiciones.split(':');

for(int i=0;i<Pos.size();i++){
    PosicionX=Pos.at(i).split(',').at(0);
    PosicionY=Pos.at(i).split(',').at(1);
    int posx,posy;

    posx=PosicionX.toInt();
    posy=PosicionY.toInt();

    qDebug()<<posx;
    if(cont==1){

        Enemigo *play=new Enemigo(posx,posy,0,0,50,3,0.08,0);
        enemigos.push_back(play);

        play->setName("enemigo");
        play->getVIDA()->show();
        play->setJugadores(Players);
        scene->addItem(play->getVIDA());



    }
    else if(cont==2){
        Ascensor *up=new Ascensor(posx,posy,100,216);
        Ascensores.push_back(up);

    }
    else{
        Obstacule *obs=new Obstacule(posx,posy,100,5);
        Obstaculos.push_back(obs);
    }
}
cont++;

}
}

for(int i=0;i<enemigos.size();i++){
    scene->addItem(enemigos[i]);
}
for(int i=0;i<Obstaculos.size();i++){
    scene->addItem(Obstaculos[i]);
}
for(int i=0;i<Ascensores.size();i++){
    scene->addItem(Ascensores[i]);
}

}

void MainWindow::puntos(){
    if(arduino->isWritable()){
        //arduino->write("1");

            QByteArray puntos;
            string Nombre;
            puntos.setNum(Players.at(0)->getPuntaje());
            qDebug()<<"PUNTOS: "<<puntos;
            arduino->write(puntos);

     }
}
