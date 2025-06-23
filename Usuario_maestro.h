#pragma once

class Usuario_maestro {

private:

public:
    ///Productos
    void cargarProducto ();
    void mostrarProductosActivos(Productos registro);
    void eliminarProducto ();
    void modificarProducto ();
    void listarProductos();

    ///Proveedores
    void cargarProveedor ();

    ///Compras
    void cargarCompras();



};
