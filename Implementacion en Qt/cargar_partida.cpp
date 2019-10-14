#include "cargar_partida.h"
#include "ui_cargar_partida.h"
#include <QFile>
#include <QString>
#include <QtDebug>
#include "login.h"
Cargar_partida::Cargar_partida(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cargar_partida)
{
    ui->setupUi(this);
    log = new Login(this);
}

Cargar_partida::~Cargar_partida()
{
    delete ui;

}

void Cargar_partida::on_pushButton_clicked()
{
    QFile file;
    QString partida=ui->lineEdit->text();
    QString n= log->getUsuario();
    qDebug()<<n;
    QString Nombre_Partida;
    QString Informacion;
    QString diretorio("C:/Users/Mateo/Desktop/ProyectoFinalAdventure-Imagenes/Implementacion en Qt/Usuarios/");
    file.setFileName(diretorio+n+".txt");
    file.open(QIODevice::ReadOnly);
    int c=0;
    while(!file.atEnd()){
        QByteArray line = file.readLine();
        QString linea;
        QStringList Datos;
        ;
        linea=line;
        linea.remove(0,9);
        Datos=linea.split("|datos:");
        Nombre_Partida=Datos[0];
        Datos[1].split(",");
        Informacion=Datos[1];
        qDebug()<<Nombre_Partida;
        qDebug()<<Informacion;
        if (partida==Nombre_Partida) c++;

    }
    if(c>0){

    }else{
        ui->label_3->setText("Partida no Encontrada");
        /*QString partidas;
        while(!file.atEnd()){
            QByteArray line = file.readLine();
            QString linea;
            QStringList Datos;
            linea=line;
            linea.remove(0,9);
            Datos=linea.split("|datos:");
            Nombre_Partida=Datos[0];


        }*/
    }


}
