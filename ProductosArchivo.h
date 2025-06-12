#pragma once
#include "Productos.h"
#include <string>


class ProductosArchivo {


 private:
     std::string _nombreArchivo;

 public:
    ProductosArchivo();
    ProductosArchivo(std::string nombreArchivo);
    bool Guardar (Productos prod);
    bool Modificar (Productos mod, int pos);
    bool Eliminar ();
    int cantidadTotalProductos ();
    int buscarProducto(std::string IDProducto);
    Productos leer( int pos);






};
