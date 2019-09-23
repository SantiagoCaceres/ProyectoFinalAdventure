#include "login.h"

Login::Login()
{
}
void Login::verificacion()
{
  string data;
  string nombre,nom,contra;
  fstream usuario;
  bool salir=false;
  int c=0;
  usuario.open("Users.txt",ios::in);
  cout<<"escribe tu nombre de usuario :"<<endl;
  cin>>nombre;
  while(!usuario.eof()){
      usuario>>data;
      if (data=="") break;
      nom=data;
      nom.erase(0,5);
      nom.resize(nom.find("|"));
      if (nombre==nom) {
          c++;
          break;
      }
    }
  if (c==1) {

     cout<<"Escribe tu caontrasena : "<<endl;
     cin>>contra;
     cin.ignore();
     nom=data;
     nom.erase(0,nom.find("|")+10);
     while(contra!=nom){
         cout<<"contrasena incorrecta..."<<endl;
         cout<<"Escribe tu caontrasena : "<<endl;
         cin>>contra;

     }
     cout<<"   Iniciaste sesion..."<<endl;

  }
  else{
      cout<<"Cuenta no encontrada... "<<endl;
      usuario.open("Users.txt",ios::out |ios::app);
      usuario.close();


      cout<<nombre<<endl;
      cout<<"1-Igresar usuario otra ves"<<endl;
      cout<<"2-o Registrarse"<<endl;
      cout<<"3-salir"<<endl;
      int n;
      cin>>n;
      while(n==1 or n==2 or n==3){

          if (n==1){verificacion();
            n=4;
          }
          if (n==2){Registro();
            n=4;
          }
          if (n==3) cout<<"saliste.."<<endl;
      }

 }
  usuario.close();


}
void Login::Registro(){
    void comprobar();
    comprobar();
    string password1,password2;
    fstream file;
    file.open("Users.txt",ios::out |ios::app);
    cout<<"Ingresa tu contrasena : ";
    cin>>password1;
    cout<<"Ingresa tu contrasena : ";
    cin>>password2;
    while(password1!=password2){
        cout<<"Ingresa tu contrasena : ";
        cin>>password2;
    }
    file <<"|password:"+password2 << endl;
    file.close();
    cout<<"Ahora estas registrado ..."<<endl;
}
void comprobar(){
    string data;
    string name,nom;
    fstream file;
    file.open("Users.txt",ios::in |ios::app);
    cout << "Ingresa tu nombre de usuario : ";
    cin>>name;
    while(!file.eof()){
        file>>data;
        if (data=="") break;
        nom=data;
        nom.erase(0,5);
        nom.resize(nom.find("|"));
        if(name==nom){
            nom="";
            name="";
            cout << "Este nombre no esta diaponible, escoge otro usuario : "<<endl;
            comprobar();
            break;

        }
    }
    file.close();
    if(name!=""){
        fstream outfile;
        outfile.open("Users.txt",ios::out |ios::app);
        outfile<<"user:"+name;
        outfile.close();
    }
}
