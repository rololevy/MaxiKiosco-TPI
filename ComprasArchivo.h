#pragma once
#include <string>
#include "Compras.h" 

class ComprasArchivo {
private:
    std::string _nombreArchivo;

public:
    ComprasArchivo(std::string nombreArchivo);
    Compras leerUno(int pos);
    bool guardar(Compras maxi);
    bool modificar(Compras maxi, int pos);
    bool eliminar(Compras maxi, int pos);
    void listarTodos();
    int getCantidadRegistros();
};
