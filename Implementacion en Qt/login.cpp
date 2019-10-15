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

}

void Login::on_pushButton_clicked()
{
    Verificar();
}

void Login::on_pushButton_2_clicked()
{
    regist->show();
}

bool Login::getEntrada() const
{
    return Entrada;
}

void Login::Verificar()
{
    QString user=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    QFile Users;
    Users.setFileName("C:/Users/Mateo/Desktop/Implementacion en Qt/Users.txt");
    Users.open(QIODevice::ReadOnly);
    int c=0;
    QString name="";
    QString pass;
    while (!Users.atEnd()) {
            QByteArray line = Users.readLine();
            QString linea;
            QStringList Datos;

            linea=line;
            linea.remove(0,5);
            Datos=linea.split("|pass:");
            name=Datos[0];
            Datos[1].split("\n");
            pass=Datos[1][0];
            if (name==user) c++;
            if (line.size()==0){
                regist->show();
            }
        }
        if (c>0){
           if (pass==password){
              setUsuario(name);
              setEntrada(true);
              //Cargar partida
           }
           else if(pass!=password){
                ui->label_5->clear();
                ui->label_4->setText("   Lo siento, no es la contraseÃ±a correcta");

           }

        } else{
            ui->label_5->setText("Este nombre no existe. Indica otro nombre o Registrate.");
            Users.close();
        }



   // Users.close();
}

void Login::setEntrada(bool value)
{
    Entrada = value;
}
void Login::Delete(){
    this->close();
}

QString Login::getUsuario() const
{
    return Usuario;
}

void Login::setUsuario(const QString &value)
{
    Usuario = value;
}
