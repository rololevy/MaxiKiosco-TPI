#pragma once
#include "Productos.h"
#include "Proveedores.h"

class Usuario_maestro {

private:

public:
    ///Productos
    void cargarProducto ();
    void eliminarProducto ();
    void modificarProducto ();


    ///Proveedores
    void cargarProveedor ();
    void mostrarProveedoresActivos(Proveedores reg);
    void eliminarProveedores ();
    void modificarProveedores ();
    void listarProveedores();

    ///Compras
    void cargarCompras();



};
