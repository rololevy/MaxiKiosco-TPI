#pragma once
#include "Productos.h"

class Consultas {
public :
    Consultas ();
    void menuconsultas();
    void mostrarProveedoresActivos();
    void mostrarProductosActivos();
    void consultarProveedorPorCUIT();
    void consultarProveedorPorTelefono();
    void consultarProveedorPorEmail();
    void consultarProveedorPorDireccion();
    void listarProductosPorCantidad();
    void listarProductosPorTipo();
    void listarProductosPorPrecio();

};
