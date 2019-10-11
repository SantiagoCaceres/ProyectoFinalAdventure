#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QList>
#include "obstacule.h"
#include "enemigo.h"
#include "ascensor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void actualizarmapa();

private:
    QGraphicsScene *scene=new QGraphicsScene;
    QList <Personaje *> Players;
    QList <Enemigo *> enemigos;
    QList <Obstacule *> Obstaculos;
    QList <Ascensor *> Obstaculosdas;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
