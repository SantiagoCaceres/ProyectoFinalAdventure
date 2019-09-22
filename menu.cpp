#include "menu.h"

Menu::Menu()
{
}

void Menu::Cargar_Guardar_Partida(personaje &principal, map<vector<int>,Enemigo> &a){
    int opcion;
    cout<<"Desea guardar partida: ";
    cin>>opcion;
    if(opcion==1){
        string direccion;
        string nombre;
        cout<<"Ingrese un nombre para la partida: ";
        cin>>nombre;
        fstream archivo;
        archivo.open(("C://Users//santy//Desktop//Codigo_Santy//ProyectoFinalAdventure//"+nombre+".txt").c_str(),ios::out);
        archivo<<principal.getX()<<","<<principal.getY()<<endl;
        archivo<<principal.getVida()<<","<<principal.getDefensa()<<","<<principal.getVelocidad()<<","<<principal.getNivel()<<","<<principal.getExperiencia()<<","<<principal.getPuntos()<<endl;
        archivo<<principal.getCuerpo()<<endl;
        //Arma
        archivo<<principal.getTipo1()->getNombre()<<endl;
        archivo<<"---"<<endl;
        //posiciones
        for (auto i=a.begin();i!=a.end();i++) {
            archivo<<i->first.at(0)<<","<<i->first.at(1)<<endl;
             archivo<<i->second.getVida()<<","<<i->second.getDefensa()<<","<<i->second.getVelocidad()<<endl;
             archivo<<i->second.getCuerpo()<<endl;
             archivo<<i->second.getTipo1()->getNombre()<<endl;
             archivo<<"---"<<endl;
        }
    }


}
/*int a,int b,int c,int d,int e,Arma &x,char z,int n,
    vida=a;
    experiencia=b;
    defensa=c;
    nivel=d;
    velocidad=e;
    tipo1=&x;
    cuerpo=z;
*/
