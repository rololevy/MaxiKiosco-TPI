#pragma once
#include "Proveedores.h"

class ProveedorArchivo{
private:
    std::string _nombreArchivo;
    bool _registroActivo;

public:
    ProveedorArchivo(std::string nombreArchivo);
    ProveedorArchivo();
    Proveedores leerUno(int pos);
    bool Guardar(Proveedores maxi);
    bool Modificar(Proveedores maxi, int pos);
    bool Eliminar(Proveedores maxi,int pos);
    //int listarTodos(Proveedores *vector, int cantRegistros);
    int getCantidadRegistros();
    int listarTodos();

    void setregActivo(bool estado);
    bool getregActivo();
};





