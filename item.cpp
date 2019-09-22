#include "item.h"
#include <sstream>

item::item(string a)
{
name=a;
}

void item::cualidad(){
    fstream archivo;
    string aux;
    archivo.open("C://Users//santy//Desktop//Codigo_Santy//ProyectoFinalAdventure//Items.txt",ios::in);
    while(!archivo.eof()){
        getline(archivo,aux);
        if(aux.substr(0,aux.find(':'))==name){
            aux=aux.substr(aux.find(':')+1);
            //vida
            stringstream geek(aux.substr(0,aux.find(',')));
            geek>>vida;
            aux=aux.substr(aux.find(',')+1);
            stringstream gek(aux.substr(0,aux.find(',')));
            gek>>defensa;
            aux=aux.substr(aux.find(',')+1);
            stringstream gk(aux.substr(0,aux.find(',')));
            gk>>velocidad;
            break;
        }
    }

}
