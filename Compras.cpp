#include "Compras.h"
#include <cstring>
#include <iostream>
using namespace std;

// Constructor por defecto
Compras::Compras() {
    strcpy(idProveedor, "");
    strcpy(idCompra, "");
    importe = 0.0f;
    activo = true;
}

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

bool Compras::getActivo() const {
    return activo;
}

// Setters
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

void Compras::setActivo(bool estado) {
    activo = estado;
}

// Mostrar datos
void Compras::mostrar() const {
    cout << "ID Compra: " << idCompra << endl;
    cout << "ID Proveedor: " << idProveedor << endl;
    cout << "Fecha: ";
    fecha.mostrar(); // asumimos que Fecha tiene un método mostrar()
    cout << "Importe: $" << importe << endl;
    cout << "Activo: ";
        if (activo) {
            cout << "Sí";
        } else {
            cout << "No";
        }
        cout << endl;
    cout << "-----------------------------" << endl;
}
