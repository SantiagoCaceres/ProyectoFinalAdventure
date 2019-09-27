#include "enemigo.h"
#include "mapa.h"
#include "item.h"
#include "obstaculo.h"
#include "menu.h"
<<<<<<< HEAD
int main() {
    Menu w;
    Arma uno("Excalibur",10,3,100);
=======
#include "login.h"
#include <stdlib.h>
int main() {
    Menu w;
    int opcion;


    Login w1;
    bool salir=false;
    do{
        cout<<"1.iniciar sesion"<<endl;
        cout<<"2. Registrarse"<<endl;
        cout<<"3.               salir"<<endl;
        cout<<"Que quieres hacer? "<<endl<<": ";
        cin>>opcion;
    switch (opcion) {
        case 1:
            w1.verificacion();

            break;
        case 2:
            w1.Registro();
            break;
        case 3:
            cout<<"salir";
            salir=true;
        default: cout<<"Choice other than 1, 2 and 3"<<endl;
           break;
    }
    system("pause");
    system("cls");

    }while(salir!=true);
    /*Arma uno("Excalibur",10,3,100);
>>>>>>> 95f7ddac94fb402191b83a10c6bbef1235e94822
    Arma uo("Martillo",2,4,2);
    personaje principal(100,0,20,0,1,uno,'*');
    mapa enemigos;
    enemigos.generar(3,1,principal,uo);
    Obstaculo s(0,21);
    map<vector<int>,Enemigo> r;
    r=enemigos.Get_Mapa();
    while(true){
    char a;
    a = char(_getch());
    if(a=='c'){break;}
    else if(a=='p'){ w.Cargar_Guardar_Partida(principal,r);}
    principal.desplazamiento(a);
    s.Dano_Area(r,principal);
    enemigos.enemis_attack();
    principal.estado();

    }

    item a("Botas_Doran");
    a.cualidad();
    return 0;
}

