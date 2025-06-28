#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

class informes{

public:
    void mostrarMenu();
    void productosConMasStock();
    void productosConMenosStock();
    void comprasPorMes();
    void Listardatos();
    void productosStockBajo(int umbral = 5);
    void cantidadProductosActivosInactivos();
    void totalGastadoPorMes();
    void proveedorMasCompras();
    void top3ProveedoresMasFrecuentes();
    void cantidadProveedoresActivosInactivos();
    // Listados ordenados
    void listarProveedoresPorID();
    void listarProveedoresPorNombre();
    void listarProductosPorID();
    void listarProductosPorNombre();
    void listarComprasPorProveedor();
    void listarComprasPorFecha();
    void listarComprasPorImporte();
};

#endif // INFORMES_H_INCLUDED
