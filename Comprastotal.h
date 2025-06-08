#pragma once

class Comprastotal {
private:
    char idProducto[30];
    char idCompra[30];
    int cantidad;
    float importe;

public:
    // Getters
    const char* getIDProducto() const;
    const char* getIDCompra() const;
    int getCantidad() const;
    float getImporte() const;

    // Setters
    void setIDProducto(const char* nuevoIDProducto);
    void setIDCompra(const char* nuevoIDCompra);
    void setCantidad(int nuevaCantidad);
    void setImporte(float nuevoImporte);
};
