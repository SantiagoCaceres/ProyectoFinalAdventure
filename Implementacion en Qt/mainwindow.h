#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QList>
#include "obstacule.h"
#include "enemigo.h"
#include "ascensor.h"
#include "login.h"
#include"menu.h"

#include <QSerialPort>
#include <QSerialPortInfo>
namespace Ui {
class MainWindow;
}
class QSerialPort;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();
    void actualizarmapa();
    void verificar();
    void cambiar_nivel();
    void puntos();
    void menu();


private:
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    QString arduino_port_name;
    bool arduino_is_available;
    bool t=false;
    Login *a;
    Menu *m;
    QTimer *timerr=new QTimer;
    QGraphicsScene *scene=new QGraphicsScene;
    QList <Personaje *> Players;
    QList <Enemigo *> enemigos;
    QList <Obstacule *> Obstaculos;
    QList <Ascensor *> Ascensores;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
