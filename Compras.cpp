#include "Compras.h"
#include <cstring>

// Getters
const char* Compras::getIdProveedor() const {
    return idProveedor;
}

const char* Compras::getIdCompra() const {
    return idCompra;
}

Fecha Compras::getFecha() const {
    return fecha;
}

float Compras::getImporte() const {
    return importe;
}

void Compras::setIdProveedor(const char* id) {
    strcpy(idProveedor, id);
}

void Compras::setIdCompra(const char* id) {
    strcpy(idCompra, id);
}


void Compras::setFecha(const Fecha& nuevaFecha) {
    fecha = nuevaFecha;
}

void Compras::setImporte(float nuevoImporte) {
    importe = nuevoImporte;
}