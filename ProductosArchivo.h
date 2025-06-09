#pragma once
#include "Productos.h"
#include <string>


class ProductosArchivo {


 private:
     std:string _nombreArchivo;

 public:
    ProductosArchivo();
    ProductosArchivo(std::string nombreArchivo);
    bool guardar (Productos prod);




};
