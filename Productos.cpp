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
 _estado=false;

 
};
 Productos::Producto(std::string IDProducto, std::string nombreProducto, std::string tipoProducto, float precio, int stock, bool estado){
strcpy(_IDProducto, IDProducto.c_str());
strcpy (_nombreProducto, nombreProducto.c_str());
strcpy (_tipoProducto, tipoProducto.c_str());
 _precioUnitario= precio;
 _stock= stock;
 _estado= estado;


     
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
bool Productos::getEstado (){
return _estado;
}
///--------------------------------------------------------------------------------------------------
void Productos::setIDProducto(std::string IDProducto) {
    strcpy (_IDProducto, IDProducto.c_str());
}

void Productos::setnombreProducto(std::string nombre) {
   strcpy (_nombreProducto, nombre.c_str());
}

void Productos::settipoProducto(std::string tipo) {
    strcpy (_tipo, tipo.c_str());
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
