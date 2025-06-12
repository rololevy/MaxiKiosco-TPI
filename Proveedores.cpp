#include <iostream>
#include <cstring>
#include "Proveedores.h"

using namespace std;


int Proveedores::getidProveedor() const{
return _idProveedor;
}

const char* Proveedores::getCUIT() const{
return _CUIT;
}

const char* Proveedores::getNombre() const{
return _Nombre;
}

const char* Proveedores::getTelefono() const{
return _Telefono;
}

const char* Proveedores::getemail() const{
return _email;
}

const char* Proveedores::getDireccion() const{
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
   Cargar();
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
