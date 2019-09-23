#include "login.h"

Login::Login()
{
}
void Login::verificacion()
{
  string data;
  string nombre,nom,contra;
  fstream usuario;
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

  }
  else{
      usuario.open("Users.txt",ios::out |ios::app);
      usuario.close();
      cout<<"Cuenta no encontrada crea un usuario "<<endl;
      cout<<"Volver a Igresar el usuario"<<endl;
      cout<<"o Registrarse";
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
        nom=data;
        nom.erase(0,5);
        nom.resize(nom.find("|"));
        cout<<"nom: "<<nom<<endl;
        cout<<"data : "<<data<<endl;
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
