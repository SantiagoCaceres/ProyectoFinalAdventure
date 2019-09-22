#include "personaje.h"

//Especial consola
//Funcion auxiliar para tener una representacion de grafica de todo lo que se implementa
void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}
//Especial consola


void personaje::setY(int value)
{
    y = value;
}

void personaje::setX(int value)
{
    x = value;
}

int personaje::getY() const
{
    return y;
}

int personaje::getX() const
{
    return x;
}

char personaje::getCuerpo() const
{
    return cuerpo;
}

void personaje::setVida(int value)
{
    vida = value;
}

int personaje::getVida() const
{
    return vida;
}

personaje::personaje(int a,int b,int c,int d,int e,Arma &x,char z){
    vida=a;
    experiencia=b;
    defensa=c;
    nivel=d;
    velocidad=e;
    tipo1=&x;
    cuerpo=z;
}

int personaje::estado(){
    //Cada que se realice un ataque o un movimiento se verificara el estado del enemigo o del usuario
    gotoxy(30,0);
    cout<<"Vida: ";
    for(int i=0;i<vida/10;i++){cout<<'#';}
    if(vida<=0){
        gotoxy(10,0);
        cout<<"Acabas de morir"<<endl;//desplegar mensaje si es el personaje del usuario
        system("pause");
        system("CLS");
        respawn();
        return(1);

    }
}


void personaje::respawn(){
    //Cada que el usuario se regenere el metodo respawn inicializará algunas estadisticas y reacomodará la posicion del usuario, ejecutando la animacion de muerte
    vida=100;
    puntos=0;
    experiencia=0;
    gotoxy(x,y);
    cout<<"Animacion de muerte"<<endl;
    system("pause");
    system("CLS");
    gotoxy(x,y);
    cout<<' ';
    x=0;y=0;//Se inicia la posicion al comienzo del nivel;
    gotoxy(x,y);
    cout<<cuerpo;
}

void personaje::desplazamiento(char tecla){
    //Este metodo recibe un char que sera la tecla presionada por el usuario, se encagara se visualizar la posicion del jugador y de realizar sus respectivos movimientos, ya sea un ataque o un desplazamiento, tambien tiene una funcion auxiliar y es actualizar la vida del usuario graficamente
    gotoxy(10,0);
    for(int i=0;i<vida/10;i++){cout<<' ';}
    for(int i=0;i<velocidad;i++){
    gotoxy(x,y);
    cout<<" ";}

    if(tecla=='d' or tecla=='D' ){
        if(x+1<=119)
        x=x+1;
    }
    else if(tecla=='s' or tecla=='S' ){
        if(y+1<=29)
        y=y+1;
    }
    else if(tecla=='a' or tecla=='A'){
        if(x-1>=0){
        x=x-1;}
    }
    else if(tecla=='w' or tecla=='W'){
        if(y-1>=0){
        y=y-1;}
    }
    if(tecla=='f'){attack(1,'d');
    }
    gotoxy(x,y);
    cout<<cuerpo;
}

void personaje::attack(int a,char b){
    //el metodo realiza la animacion de ataque cada vez que se ejecute; recibe un entero y un char como parametros para verificar quien realiza la animacion y a que direccion se ejecuta
    gotoxy(x,y);
    if(a==1){
            cout<<"*";
    }
   else{
        cout<<"+";
   }
   if(b=='d' or b=='D'){
    for(int i=1;i<tipo1->getAlcance();i++){

        cout<<"-";}
    cout<<">";

    Sleep(100);
    gotoxy(x+1,y);
    for(int i=0;i<tipo1->getAlcance();i++){
        cout<<" ";}}
   else if(x-tipo1->getAlcance()>=0){
       gotoxy(x-tipo1->getAlcance(),y);
       cout<<"<";
       for(int i=1;i<tipo1->getAlcance();i++){

           cout<<"-";}
       Sleep(100);
       gotoxy(x-tipo1->getAlcance(),y);
       for(int i=0;i<tipo1->getAlcance();i++){
           cout<<" ";}
   }
    //condicional para ver si hay enemigos en esa pocicion
}

/* Falta implementar el retroceso del arma si se efectua un ataque exitoso aparte de poder realizar daño a los enemigos
Impementar el Progress(); y autoLevel(); son metodos que definiremos cuando tengamos bien definido como será el proceso del mapa
y la interracion con los enemigos en QtGraphics
*/
