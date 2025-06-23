#pragma once
#include <string>


class Proveedores{

private:
    int _idProveedor;
    char _CUIT[30];
    char _Nombre[30];
    char _Telefono[30];
    char _email[30];
    char _direccion[30];
    bool _estado;


public:

Proveedores();
Proveedores(int idProveedor, std::string CUIT, std::string Nombre, std::string Telefono, std::string Email, std::string Direccion, bool estado);
int getidProveedor();
const char* getCUIT();
const char* getNombre();
const char* getTelefono();
const char* getemail();
const char* getDireccion();
void setidProveedor(const int Proveedor);
void setCUIT(const char* CUIT);
void setNombre(const char* Nombre);
void setTelefono(const char* Telefono);
void setEmail(const char* Email);
void setDireccion(const char* Direccion);
void Cargar();
void Mostrar();
void setEstado(bool estado);
bool getEstado();
void Opcmenu();

};







