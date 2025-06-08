#pragma once
#include <string>


class Proveedores{

private:
    std::string _idProveedor;
    std::string _CUIT;
    std::string _Nombre;
    std::string _Telefono;
    std::string _email;
    std::string _direccion;
    bool _estado;


public:

std::string getidProveedor() const;
std::string getCUIT() const;
std::string getNombre() const;
std::string getTelefono() const;
std::string getemail() const;
std::string getDireccion() const;
void setidProveedor(const std::string& Proveedor);
void setCUIT(const std::string& CUIT);
void setNombre(const std::string& Nombre);
void setTelefono(const std::string& Telefono);
void setEmail(const std::string& Email);
void setDireccion(const std::string& Direccion);
void Cargar();
void Mostrar();
void Eliminar();
void Opcmenu();

};







