#include <iostream>
#include "Proveedores.h"

using namespace std;


std::string Proveedores::getidProveedor() const{
return _idProveedor;
}

std::string Proveedores::getCUIT() const{
return _CUIT;
}

std::string Proveedores::getNombre() const{
return _Nombre;
}

std::string Proveedores::getTelefono() const{
return _Telefono;
}

std::string Proveedores::getemail() const{
return _email;
}

std::string Proveedores::getDireccion() const{
return _direccion;
}

void Proveedores::setidProveedor(const std::string& Proveedor){
_idProveedor=Proveedor;
}

void Proveedores::setCUIT(const std::string& CUIT){
_CUIT=CUIT;
}

void Proveedores::setNombre(const std::string& Nombre){
_Nombre=Nombre;
}

void Proveedores::setTelefono(const std::string& Telefono){
_Telefono=Telefono;
}

void Proveedores::setEmail(const std::string& Email){
_email=Email;
}

void Proveedores::setDireccion(const std::string& Direccion){
_direccion=Direccion;
}

void Proveedores::Cargar(){
string idProv, CUIT, Nombre, Telefono, Email, Direccion;



cout << "Carga de IDProveedor" << endl;
getline(cin,idProv);
setidProveedor(idProv);
cout << "Carga de CUIT" << endl;
getline(cin,CUIT);
setCUIT(CUIT);
cout << "Carga de Nombre" << endl;
getline(cin,Nombre);
setNombre(Nombre);
cout << "Carga de Telefono" << endl;
getline(cin,Telefono);
setTelefono(Telefono);
cout << "Carga de Email" << endl;
getline(cin,Email);
setEmail(Email);
cout << "Carga de Direccion" << endl;
getline(cin,Direccion);
setDireccion(Direccion);
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

void Proveedores::Eliminar(){

_estado=false;

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
    Eliminar();
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
