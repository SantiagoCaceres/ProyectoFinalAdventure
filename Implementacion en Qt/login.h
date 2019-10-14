#ifndef LOGIN_H
#define LOGIN_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QDialog>
#include "registro.h"
#include <QMessageBox>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool Entrar(bool n);

    void setEntrada(bool value);

    bool getEntrada() const;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void Delete();
private:

    Ui::Login *ui;
    Registro * regist;
    bool Entrada=false;
};

#endif // LOGIN_H
