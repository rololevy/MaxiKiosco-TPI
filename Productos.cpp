#include <iostream>
#include <cstring>
#include "Productos.h"

using namespace std;

int Productos::getIDProducto() {
    return _IDProducto;
}

const char* Productos::getnombreProducto() {
    return _nombreProducto;
}

const char* Productos::gettipoProducto() {
    return _tipoProducto;
}

float Productos::getprecioUnitario() {
    return _precioUnitario;
}

int Productos::getstock() {
    return _stock;
}

void Productos::setIDProducto(int ID) {
    _IDProducto = ID;
}

void Productos::setnombreProducto(string nombre) {
    strncpy(_nombreProducto, nombre.c_str(), sizeof(_nombreProducto));
    _nombreProducto[sizeof(_nombreProducto) - 1] = '\0';
}

void Productos::settipoProducto(string tipo) {
    strncpy(_tipoProducto, tipo.c_str(), sizeof(_tipoProducto));
    _tipoProducto[sizeof(_tipoProducto) - 1] = '\0';
}

void Productos::setprecioUnitario(float precio) {
    _precioUnitario = precio;
}

void Productos::setstock(int stock) {
    _stock = stock;
}

void Productos::cargar() {
    string nombre, tipo;
    float precio;
    int stock, id;

    cout << "Ingrese ID del producto: ";
    cin >> id;
    setIDProducto(id);

    cin.ignore(); // limpiar buffer

    cout << "Ingrese nombre del producto: ";
    getline(cin, nombre);
    setnombreProducto(nombre);

    cout << "Ingrese tipo de producto: ";
    getline(cin, tipo);
    settipoProducto(tipo);

    cout << "Ingrese precio unitario: ";
    cin >> precio;
    setprecioUnitario(precio);

    cout << "Ingrese stock: ";
    cin >> stock;
    setstock(stock);

    _estado = true;
}

void Productos::mostrar() {
    if (_estado) {
        cout << "ID Producto: " << _IDProducto << endl;
        cout << "Nombre: " << _nombreProducto << endl;
        cout << "Tipo: " << _tipoProducto << endl;
        cout << "Precio Unitario: $" << _precioUnitario << endl;
        cout << "Stock: " << _stock << endl;
    } else {
        cout << "Producto eliminado o inactivo." << endl;
    }
}

void Productos::eliminar() {
    _estado = false;
}
