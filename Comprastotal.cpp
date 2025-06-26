using namespace std;
#include <iostream>
#include "Comprastotal.h"
#include <cstring>


Comprastotal::Comprastotal() {
    strcpy(idProducto, "");
    strcpy(idCompra, "");
    cantidad = 0;
    importe = 0.0f;
}


Comprastotal::Comprastotal(std::string idProd, std::string idComp, int cant, float imp) {
    setIDProducto(idProd);
    setIDCompra(idComp);
    cantidad = cant;
    importe = imp;
}


std::string Comprastotal::getIDProducto() {
    return idProducto;
}

std::string Comprastotal::getIDCompra() {
    return idCompra;
}

int Comprastotal::getCantidad() {
    return cantidad;
}

float Comprastotal::getImporte() {
    return importe;
}


void Comprastotal::setIDProducto(std::string idProd) {
    strcpy(idProducto, idProd.c_str());
}

void Comprastotal::setIDCompra(std::string idComp) {
    strcpy(idCompra, idComp.c_str());
}

void Comprastotal::setCantidad(int cant) {
    cantidad = cant;
}

void Comprastotal::setImporte(float imp) {
    importe = imp;
}


void Comprastotal::cargar() {
    string prod, comp;
    cout << "ID Producto: ";
    cin.ignore();
    getline(cin, prod);
    setIDProducto(prod);

    cout << "ID Compra: ";
    getline(cin, comp);
    setIDCompra(comp);

    cout << "Cantidad: ";
    cin >> cantidad;

    cout << "Importe: ";
    cin >> importe;


}

