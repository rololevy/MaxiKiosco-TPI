#pragma once
#include "Fecha.h"
#include <iostream>

class Compras {
private:
    char idProveedor[30];
    char idCompra[30];
    Fecha fecha;
    float importe;
    bool activo;

public:
    // Constructor por defecto
    Compras();

    // Getters
    const char* getIdProveedor() const;
    const char* getIdCompra() const;
    Fecha getFecha() const;
    float getImporte() const;
    bool getActivo() const;

    // Setters
    void setIdProveedor(const char* id);
    void setIdCompra(const char* id);
    void setFecha(const Fecha& fecha);
    void setImporte(float importe);
    void setActivo(bool estado);

    // Métodos útiles
    void mostrar() const;
};
