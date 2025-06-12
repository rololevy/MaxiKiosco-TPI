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

int getidProveedor() const;
const char* getCUIT() const;
const char* getNombre() const;
const char* getTelefono() const;
const char* getemail() const;
const char* getDireccion() const;
void setidProveedor(const int Proveedor);
void setCUIT(const char* CUIT);
void setNombre(const char* Nombre);
void setTelefono(const char* Telefono);
void setEmail(const char* Email);
void setDireccion(const char* Direccion);
void Cargar();
void Mostrar();
void setEstado(bool estado);
void Opcmenu();

};







