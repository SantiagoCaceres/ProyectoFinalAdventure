#include "registro.h"
#include "ui_registro.h"
#include <QDebug>
#include <QFile>
#include <QLabel>
#include <QTextStream>
Registro::Registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
}

Registro::~Registro()
{
    delete ui;
}

void Registro::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString pass=ui->lineEdit_2->text();
    QString pass_conf=ui->lineEdit_3->text();
    QFile Users;
    Users.setFileName("C:/Users/Mateo/Desktop/login_simulation/Users.txt");
    Users.open(QIODevice::ReadOnly);
    int c=0;
    while (!Users.atEnd()) {
        QByteArray line = Users.readLine();
        QString linea;
        QStringList Datos;
        QString name;
        linea=line;
        linea.remove(0,5);
        Datos=linea.split("|pass:");
        name=Datos[0];
        if (name==user) c++;
    }
    Users.close();
    if (c==0){
        if (pass==pass_conf and pass!=""){
        Users.setFileName("C:/Users/Mateo/Desktop/login_simulation/Users.txt");
        Users.open(QIODevice::Append);
            QTextStream stream(&Users);
            stream <<"User:"<<user;
            stream <<"|pass:"<<pass;
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();

            close();
       //QFile name (user);

        }

        else if(pass=="" or pass_conf =="") {
            ui->label_5->setText("   Completa las Contraseñas");
        }
        else{
            ui->label_5->setText("   Las contraseñas no coinciden");
        }

    }else{
            ui->label_5->setText("   Alguien tiene este nombre. Prueba con otro.");
        }
    Users.close();
    //ui->lineEdit->clear();


}



