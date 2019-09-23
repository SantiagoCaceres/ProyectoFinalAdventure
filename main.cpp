#include "enemigo.h"
#include "mapa.h"
#include "item.h"
#include "obstaculo.h"
#include "menu.h"
#include "login.h"
int main() {
    Menu w;
    int opcion;

    cout<<"1.iniciar sesion"<<endl;
    cout<<"2. Registrarse"<<endl;
    cout<<"3.               salir"<<endl;
    cout<<"Que quieres hacer? "<<endl<<": ";
    cin>>opcion;
    Login w1;
    bool salir=false;
    do{
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
            //Implementar salida
        default: cout<<"Choice other than 1, 2 and 3"<<endl;
           break;
    }
    }while(salir==true);
    /*Arma uno("Excalibur",10,3,100);
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
    principal.desplazamiento(a);
    s.Dano_Area(r,principal);
    enemigos.enemis_attack();
    principal.estado();
    }
    w.Cargar_Guardar_Partida(principal,r);
    item a("Botas_Doran");
    a.cualidad();*/
    return 0;
}

