#include <cstring>
#include <iostream>
using namespace std;
#include "Compras.h"

// Constructor por defecto
Compras::Compras() {
    strcpy(idProveedor, "");
    strcpy(idCompra, "");
    importe = 0.0f;
    activo = true;
}

Compras::Compras(std::string IDcompra,std::string idPROV,Fecha fecha,float Importe, int estado){  /// agrego para informes
    strcpy (idCompra, IDcompra.c_str());
    strcpy (idProveedor, idPROV.c_str());
    _fecha= fecha;
    importe=Importe;
    activo=estado;
 }

// Getters
const char* Compras::getIdProveedor() {
    return idProveedor;
}

const char* Compras::getIdCompra() {
    return idCompra;
}

Fecha Compras::getFecha(){
    return _fecha;
}

float Compras::getImporte() {
    return importe;
}

bool Compras::getActivo(){
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
    _fecha = nuevaFecha;
}

void Compras::setImporte(float nuevoImporte) {
    importe = nuevoImporte;
}

void Compras::setActivo(bool estado) {
    activo = estado;
}

// Mostrar datos
void Compras::mostrar() {
    cout << "ID Compra: " << idCompra << endl;
    cout << "ID Proveedor: " << idProveedor << endl;
    cout << "Fecha: ";
    _fecha.Mostrar();
    cout << endl;
    cout << "Importe: $" << importe << endl;
    cout << "Activo: ";
        if (activo) {
            cout << "Si";
        } else {
            cout << "No";
        }
        cout << endl;
    cout << "-----------------------------" << endl;
}
