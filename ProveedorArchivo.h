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
    bool Guardar (Proveedores prodP, int Maxi);
    bool Modificar(Proveedores maxi, int pos);
    bool Eliminar(Proveedores maxi,int pos);
    int getCantidadRegistros();
    int listarTodos();
    int buscarProveedor(std::string IDproveedor);

    void setregActivo(bool estado);
    bool getregActivo();
};





