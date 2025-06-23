#include <iostream>
#include <cstring>
using namespace std;
#include "Proveedores.h"

Proveedores::Proveedores(){
_idProveedor=0;
strcpy (_CUIT, "");
strcpy (_Nombre, "");
strcpy (_Telefono, "");
strcpy (_email, "");
strcpy (_direccion, "");
 _estado=false;

}

Proveedores::Proveedores(int idProveedor, std::string CUIT, std::string Nombre, std::string Telefono, std::string Email, std::string Direccion, bool estado){
_idProveedor=idProveedor;
strcpy (_CUIT, CUIT.c_str());
strcpy (_Nombre, Nombre.c_str());
strcpy (_Telefono, Telefono.c_str());
strcpy (_email, Email.c_str());
strcpy (_direccion, Direccion.c_str());
 _estado= estado;


}


int Proveedores::getidProveedor(){
return _idProveedor;
}

const char* Proveedores::getCUIT(){
return _CUIT;
}

const char* Proveedores::getNombre(){
return _Nombre;
}

const char* Proveedores::getTelefono(){
return _Telefono;
}

const char* Proveedores::getemail(){
return _email;
}

const char* Proveedores::getDireccion(){
return _direccion;
}

void Proveedores::setidProveedor(const int Proveedor){
_idProveedor=Proveedor;
}

void Proveedores::setCUIT(const char* CUIT){
strcpy(_CUIT, CUIT);
}

void Proveedores::setNombre(const char* Nombre){
strcpy(_Nombre, Nombre);
}

void Proveedores::setTelefono(const char* Telefono){
strcpy(_Telefono, Telefono);
}

void Proveedores::setEmail(const char* Email){
strcpy(_email, Email);
}

void Proveedores::setDireccion(const char* Direccion){
strcpy(_direccion, Direccion);
}
/*  -----------------------------------------------------------> POSIBLEMENTE BORRAR POR MANAGER
void Proveedores::Cargar(){
string CUIT_str, Nombre_str, Telefono_str, Email_str, Direccion_str;
int idProv;

cout << "Carga de IDProveedor" << endl;
cin >> idProv;
setidProveedor(idProv);
cin.ignore();
cout << "Carga de CUIT" << endl;
getline(cin,CUIT_str);
setCUIT(CUIT_str.c_str());
cout << "Carga de Nombre" << endl;
getline(cin,Nombre_str);
setNombre(Nombre_str.c_str());
cout << "Carga de Telefono" << endl;
getline(cin,Telefono_str);
setTelefono(Telefono_str.c_str());
cout << "Carga de Email" << endl;
getline(cin,Email_str);
setEmail(Email_str.c_str());
cout << "Carga de Direccion" << endl;
getline(cin,Direccion_str);
setDireccion(Direccion_str.c_str());
_estado=true;

}
*/

void Proveedores::Mostrar(){

if(_estado){

cout << "ID del Proveedor: " << getidProveedor() << endl;
cout << "Cuit del proveedor: " << getCUIT() << endl;
cout << "Nombre: " << getNombre() << endl;
cout << "Telefono: " << getTelefono() << endl;
cout << "Email: " << getemail() << endl;
cout << "Direccion: " << getDireccion() << endl;
}
else{
    cout << "El proveedor no esta registrado en el sistema." << endl;
}

}

void Proveedores::setEstado(bool estado){
_estado=estado;
}

bool Proveedores::getEstado(){
return _estado;
}


void Proveedores::Opcmenu(){
int Opcs;
bool Salida=true;
while(Salida==true){
cout << "=================================" << endl;
cout << "1- Cargar proveedor" << endl;
cout << "2- Mostrar proveedor" << endl;
cout << "3- Borrar proveedor" << endl;
cout << "4- regresar al menu anterior" << endl;
cin >> Opcs;
cin.ignore();
switch(Opcs){
case 1:
  // Cargar();
    break;

case 2:
    Mostrar();
    break;

case 3:
   // Eliminar();
    break;

 case 4:
    Salida=false;
    break;

    default:
    exit(0);
    break;
}

}
}
