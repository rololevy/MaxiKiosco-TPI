#pragma once
#include <string>


class Proveedores{

private:
    char _idProveedor[30];
    char _CUIT[30];
    char _Nombre[30];
    char _Telefono[30];
    char _email[30];
    char _direccion[30];
    bool _estado;


public:

Proveedores();
Proveedores(std::string idProveedor, std::string CUIT, std::string Nombre, std::string Telefono, std::string Email, std::string Direccion, bool estado);
std::string getidProveedor();
std::string getCUIT();
std::string getNombre();
std::string getTelefono();
std::string getemail();
std::string getDireccion();
bool getEstado();
void setidProveedor( std::string Proveedor);
void setCUIT(std::string CUIT);
void setNombre(std::string Nombre);
void setTelefono(std::string Telefono);
void setEmail(std::string Email);
void setDireccion(std::string Direccion);
void setEstado(bool estado);


void Cargar();
void Mostrar();
void Opcmenu();

};


