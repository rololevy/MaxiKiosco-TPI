#include <iostream>
#include <cstring>
#include "Productos.h"

using namespace std;

Productos::Producto(){
strcpy(_IDProducto, "");
strcpy (_nombreProducto, "");
strcpy (_tipoProducto, "");
 _precioUnitario=0;
 _stock=0;
 _estado=0;

 
};
 Productos::Producto(std::string IDProducto, std::string nombreProducto, std::string tipoProducto, float precio, int stock, bool estado){


     
 };

std::string Productos::getIDProducto() {
    return _IDProducto;
}

std::string Productos::getnombreProducto() {
    return _nombreProducto;
}

std::string Productos::gettipoProducto() {
    return _tipoProducto;
}

float Productos::getprecioUnitario() {
    return _precioUnitario;
}

int Productos::getstock() {
    return _stock;
}
bool Productos::getestado (){
return _estado;
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

void Productos::setEstado (bool estado){

 _estado= estado;
}

void Productos::cargar() {
    string nombre, tipo;
    float precio;
    int stock, id;

    cout << "Ingrese ID del producto: ";
    cin >> id;
    setIDProducto(id);

    cin.ignore(); 

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
