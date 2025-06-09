#include <iostream>
#include <string>
using namespace std;
#include "Usuario_maestro.h"
#include "Productos.h"
#include "ProductosArchivo.h"

void Usuario_maestro::cargarProducto (){

    Productos prod;
    ProductosArchivo registro;

string IDProducto, nombreProducto, tipoProducto;
float precioUnitario;
int stock;
bool estado;

////aca se valida


cout <<"Ingrese ID Producto";
cin.ignore();
getline(cin, IDProducto);

cout << "Ingrese Nombre Producto"<< endl;
getline(cin, nombreProducto);

cout <<"Ingrese tipo de producto"<< endl;
getline(cin, tipoProducto);

cout << "Ingrese precio Unitario"<< endl;
cin>> precioUnitario;

cout <<"Ingrese precio unitario"<< endl;
cin>> precioUnitario;

cout<<"Ingrese stock"<< endl;
cin>> stock;

cout<<"Ingresar 1-si 2-no?"<< endl;
cin>>estado;

prod= Productos (IDProducto, nombreProducto, tipoProducto, precioUnitario, stock, estado);

if (registro.guardar(prod)){

    cout<< "Se guardo correctamente!";
}
else
    cout<<"Hubo un error al realizar la carga";

}

void Usuario_maestro::cargarProveedor(){

string idProv, CUIT, Nombre, Telefono, Email, Direccion;



cout << "Carga de IDProveedor" << endl;
cin.ignore();
getline(cin,idProv);

cout << "Carga de CUIT" << endl;
getline(cin,CUIT);

cout << "Carga de Nombre" << endl;
getline(cin,Nombre);

cout << "Carga de Telefono" << endl;
getline(cin,Telefono);

cout << "Carga de Email" << endl;
getline(cin,Email);

cout << "Carga de Direccion" << endl;
getline(cin,Direccion);

cout<<"Ingresar OK=1, NO=0"<< endl;
cin>>estado;



}
