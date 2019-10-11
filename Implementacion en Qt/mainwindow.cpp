#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //registro = new Registro(this);
    login = new Login(this);

    QGraphicsPixmapItem item(QPixmap("C:/Users/Mateo/Desktop/login_simulation/otre.jpg"));
    login->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_pushButton_clicked()
{
    registro->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    login->show();
}
*/
