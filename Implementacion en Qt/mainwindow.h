#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QList>
#include "personaje.h"

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

private:
    QGraphicsScene *scene=new QGraphicsScene;
    QList <Personaje *> Players;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
