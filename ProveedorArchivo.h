#pragma once
#include "Proveedores.cpp"

class ProveedorArchivo{
private:
    std::string _nombreArchivo;
    bool _registroActivo;

public:
    ProveedorArchivo(std::string nombreArchivo);
    ProveedorArchivo();
    ProveedorArchivo leerUno(int pos);
    bool Guardar(Proveedores maxi);
    bool Modificar(Proveedores maxi, int pos);
    bool Eliminar(Proveedores maxi,int pos);
    void listarTodos();
    int getCantidadRegistros();

    void setregActivo(bool estado);
    bool getregActivo();
};





