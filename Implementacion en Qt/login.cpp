#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QLabel>
#include <QtDebug>
#include <QByteArray>
#include <QTextStream>
#include "registro.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    regist = new Registro(this);
}

Login::~Login()
{
    delete ui;
    //registro = new Registro(this);
}

void Login::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    QFile Users;
    Users.setFileName("C:/Users/Mateo/Desktop/login_simulation/Users.txt");
    Users.open(QIODevice::ReadOnly);
    while (!Users.atEnd()) {
        QByteArray line = Users.readLine();
        QString linea;
        QStringList Datos;
        QString name="";
        QString pass;
        linea=line;
        linea.remove(0,5);
        Datos=linea.split("|pass:");
        name=Datos[0];
        pass=Datos[1];
        if (user==name){
           if (pass==password){
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                close();

           }
           else if(pass!=password){
                ui->label_5->clear();
                ui->label_4->setText("   Lo siento, no es la contraseña correcta");
           }


        } else{
            ui->label_5->setText("Este nombre no existe. Indica otro nombre o Registrate.");
        }

        qDebug()<<name<<"--"<<pass;



    }
}


void Login::on_pushButton_2_clicked()
{
    regist->show();
}
