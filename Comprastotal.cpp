#include "Comprastotal.h"
#include <cstring>
#include <iostream>

// Constructor por defecto
Comprastotal::Comprastotal() {
    strcpy(idProducto, "");
    strcpy(idCompra, "");
    cantidad = 0;
    importe = 0.0f;
}

// Constructor con parámetros
Comprastotal::Comprastotal(std::string idProd, std::string idComp, int cant, float imp) {
    setIDProducto(idProd);
    setIDCompra(idComp);
    cantidad = cant;
    importe = imp;
}

// Getters
std::string Comprastotal::getIDProducto() {
    return std::string(idProducto);
}

std::string Comprastotal::getIDCompra() {
    return std::string(idCompra);
}

int Comprastotal::getCantidad() {
    return cantidad;
}

float Comprastotal::getImporte() {
    return importe;
}

// Setters
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

// Métodos auxiliares
void Comprastotal::cargar() {
    std::string prod, comp;
    std::cout << "ID Producto: ";
    std::getline(std::cin, prod);
    setIDProducto(prod);

    std::cout << "ID Compra: ";
    std::getline(std::cin, comp);
    setIDCompra(comp);

    std::cout << "Cantidad: ";
    std::cin >> cantidad;

    std::cout << "Importe: ";
    std::cin >> importe;

    std::cin.ignore(); // limpiar el buffer
}

void Comprastotal::mostrar() {
    std::cout << "ID Producto: " << getIDProducto() << std::endl;
    std::cout << "ID Compra: " << getIDCompra() << std::endl;
    std::cout << "Cantidad: " << cantidad << std::endl;
    std::cout << "Importe: " << importe << std::endl;
}
