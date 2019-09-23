#include "menu.h"

Menu::Menu()
{
}

void Menu::Cargar_Guardar_Partida(personaje &principal, map<vector<int>,Enemigo> &a){
    int opcion;
    cout<<"Desea guardar partida: ";
    cin>>opcion;
    if(opcion==1){
        string nombre;
        cout<<"Ingrese un nombre para la partida: ";
        cin>>nombre;
        fstream archivo;
        archivo.open(("C://Users//santy//Desktop//Codigo_Santy//ProyectoFinalAdventure//"+nombre+".txt").c_str(),ios::out);
        archivo<<principal.getX()<<","<<principal.getY()<<':';
        archivo<<principal.getVida()<<","<<principal.getDefensa()<<","<<principal.getVelocidad()<<","<<principal.getNivel()<<","<<principal.getExperiencia()<<","<<principal.getPuntos()<<':';
        archivo<<principal.getCuerpo()<<':';
        //Arma
        archivo<<principal.getTipo1()->getNombre()<<endl;
        //posiciones
        for (auto i=a.begin();i!=a.end();i++) {
            archivo<<i->first.at(0)<<","<<i->first.at(1)<<':';
             archivo<<i->second.getVida()<<","<<i->second.getDefensa()<<","<<i->second.getVelocidad()<<':';
             archivo<<i->second.getCuerpo()<<':';
             archivo<<i->second.getTipo1()->getNombre()<<endl;
        }
        archivo.close();
    }
    else if(opcion == 2){
        string nombre;
        cout<<"Ingrese el nombre para la partida: ";
        cin>>nombre;
        fstream archivo;
        archivo.open(("C://Users//santy//Desktop//Codigo_Santy//ProyectoFinalAdventure//"+nombre+".txt").c_str(),ios::in);
        map<vector<int>,Enemigo> posEnemi;
        bool t=true;
        string datos;
        string aux;
        string aux2;
        int c;
        int x=0;
            getline(archivo,datos);
            if(t){
            aux=datos.substr(0,datos.find(':'));
            aux=aux.substr(0,aux.find(','));
            stringstream (aux)>>c;
            principal.setX(c);//ingreso la posicion x
            aux=datos.substr(0,datos.find(':'));
            aux=aux.substr(aux.find(',')+1);
            stringstream (aux)>>c;
            principal.setY(c);//ingreso la posicion y del jugador
            //
            aux=datos.substr(datos.find(':')+1);
            aux=aux.substr(0,aux.find(':'));
            for(int i=0;i<int(aux.size());i++){

                aux2.push_back(aux[i]);
                if(aux[i]==','){
                aux2.erase(--aux2.end());
                x++;

                if(x==1){
                    stringstream(aux2)>>c;
                    principal.setVida(c);
                }
                else if(x==2){
                    stringstream(aux2)>>c;
                    principal.setDefensa(c);
                }
                else if(x==3){
                    stringstream(aux2)>>c;
                    principal.setVelocidad(c);
                }
                else if(x==1){
                    stringstream(aux2)>>c;
                    principal.setNivel(c);
                }
                else if(x==1){
                    stringstream(aux2)>>c;
                    principal.setExperiencia(c);
                }
                else{
                    stringstream(aux2)>>c;
                    principal.setPuntos(c);
                }
                aux2.clear();}
            }
            //
            aux=datos.substr(datos.find(':')+1);
            aux=aux.substr(aux.find(':')+1);
            aux=aux.substr(0,aux.find(':'));
            principal.setCuerpo(aux[0]);
            //
            aux=datos.substr(datos.find(':')+1);
            aux=aux.substr(aux.find(':')+1);
            aux=aux.substr(aux.find(':')+1);
            archivo.close();
            archivo.open("C://Users//santy//Desktop//Codigo_Santy//ProyectoFinalAdventure//Armas.txt",ios::in);
            string nombre;
            int dano,alcance,probabilidad;
            while(archivo.eof()){
                getline(archivo,datos);
                if(datos.substr(0,datos.find(','))==aux){
                    nombre=aux;
                    datos=datos.substr(datos.find(','));
                    datos=datos.substr(0,datos.find(','));
                   stringstream(datos)>>dano;
                   datos=datos.substr(datos.find(','));
                   datos=datos.substr(datos.find(','));
                   datos=datos.substr(0,datos.find(','));
                   stringstream(datos)>>alcance;
                   datos=datos.substr(datos.find(','));
                   datos=datos.substr(datos.find(','));
                   datos=datos.substr(datos.find(','));
                   datos=datos.substr(0,datos.find(','));
                   stringstream(datos)>>probabilidad;
                   principal.getTipo1()->setNombre(nombre);
                   principal.getTipo1()->setDano(dano);
                   principal.getTipo1()->setProbabilidad(probabilidad);

                }
            }








        }





    }


}
