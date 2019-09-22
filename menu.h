#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <time.h>
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include <mapa.h>
#include <personaje.h>
using namespace  std;

class Menu
{
private:
    string nombre_partida;
public:
    Menu();
    void Cargar_Guardar_Partida(personaje &principal, map<vector<int>,Enemigo> &a);
    void Salir();
};

#endif // MENU_H
