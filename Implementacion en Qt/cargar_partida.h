#ifndef CARGAR_PARTIDA_H
#define CARGAR_PARTIDA_H

#include <QDialog>
#include "login.h"
namespace Ui {
class Cargar_partida;
}

class Cargar_partida : public QDialog
{
    Q_OBJECT

public:
    explicit Cargar_partida(QWidget *parent = nullptr);
    ~Cargar_partida();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Cargar_partida *ui;
    Login *log;
};

#endif // CARGAR_PARTIDA_H
