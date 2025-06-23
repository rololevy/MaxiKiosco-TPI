#pragma once
#include <cstring>
#include "Productos.h"
#include <iostream>
using namespace std;

Productos::Productos(){
strcpy(_IDProducto, "");
strcpy (_nombreProducto, "");
strcpy (_tipoProducto, "");
 _precioUnitario=0;
 _stock=0;
 _estado=false;


};
 Productos::Productos(std::string IDProducto, std::string nombreProducto, std::string tipoProducto, float precio, int stock){
setIDProducto(IDProducto);
setnombreProducto(nombreProducto);
settipoProducto (tipoProducto);
setprecioUnitario(precio);
setstock (stock);


 };
 ///--------------------------------------------------------------------------------------------------
void Productos::setIDProducto(std::string IDProducto) {
    strcpy (_IDProducto, IDProducto.c_str());

}

void Productos::setnombreProducto(std::string nombre) {
   strcpy (_nombreProducto, nombre.c_str());
}

void Productos::settipoProducto(std::string tipo) {
    strcpy (_tipoProducto, tipo.c_str());
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



