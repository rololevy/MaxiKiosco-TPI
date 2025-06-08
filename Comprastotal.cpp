#include <cstring>
#include "Comprastotal.h"

// Getters
const char* Comprastotal::getIDProducto() const {
    return idProducto;
}

const char* Comprastotal::getIDCompra() const {
    return idCompra;
}

int Comprastotal::getCantidad() const {
    return cantidad;
}

float Comprastotal::getImporte() const {
    return importe;
}

// Setters
void Comprastotal::setIDProducto(const char* nuevoIDProducto) {
    strncpy(idProducto, nuevoIDProducto, sizeof(idProducto));
    idProducto[sizeof(idProducto) - 1] = '\0'; // Null-termination
}

void Comprastotal::setIDCompra(const char* nuevoIDCompra) {
    strncpy(idCompra, nuevoIDCompra, sizeof(idCompra));
    idCompra[sizeof(idCompra) - 1] = '\0'; // Null-termination
}

void Comprastotal::setCantidad(int nuevaCantidad) {
    cantidad = nuevaCantidad;
}

void Comprastotal::setImporte(float nuevoImporte) {
    importe = nuevoImporte;
}
