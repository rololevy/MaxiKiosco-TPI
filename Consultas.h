#pragma once
#include "Productos.h"

class Consultas {
public :
    Consultas ();
    void menuconsultas();
    void mostrarProveedoresActivos();
    void mostrarProductosActivos();
    void buscarProveedorPorCUIT();
    void buscarProveedorPorTelefono();
    void buscarProveedorPorEmail();
    void buscarProveedorPorDireccion();
    void productosOrdenadosPorCantidad();
    void productosOrdenadosPorTipo();
    void productosOrdenadosPorPrecio();

};
