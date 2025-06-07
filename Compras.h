#pragma once

#include "Fecha.h"

class Compras {
private:
    char idProveedor[30];
    char idCompra[30];
    Fecha fecha;
    float importe;

public:
    // Getters
    const char* getIdProveedor() const;
    const char* getIdCompra() const;
    Fecha getFecha() const;
    float getImporte() const;

    // Setters
    void setIdProveedor(const char* id);
    void setIdCompra(const char* id);
    void setFecha(const Fecha& fecha);
    void setImporte(float importe);
};
