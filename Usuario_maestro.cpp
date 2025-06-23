#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "Usuario_maestro.h"
#include "Productos.h"
#include "ProductosArchivo.h"
#include "ProveedorArchivo.h"
#include "ComprasArchivo.h"
#include "Fecha.h"

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

cout<<"Ingrese stock"<< endl;
cin>> stock;

cout<<"Ingresar 1-si 2-no?"<< endl;
cin>>estado;

prod= Productos (IDProducto, nombreProducto, tipoProducto, precioUnitario, stock, estado);

if (registro.Guardar(prod)){

    cout<< "Se guardo correctamente!";
}
else
    cout<<"Hubo un error al realizar la carga";

}



void Usuario_maestro::cargarProveedor(){
    Proveedores proveedor;
    ProveedorArchivo ArchivodeProveedores;
char CUIT_str[30], Nombre_str[30], Telefono_str[30], Email_str[30], Direccion_str[30];
int idProv;
bool Estado;

cout << "Carga de IDProveedor" << endl;
cin >> idProv;
proveedor.setidProveedor(idProv);
cin.ignore();

cout << "Carga de CUIT" << endl;
cin >> CUIT_str;
proveedor.setCUIT(CUIT_str);

cout << "Carga de Nombre" << endl;
proveedor.setNombre(Nombre_str);
cin >> Nombre_str;

cout << "Carga de Telefono" << endl;
proveedor.setTelefono(Telefono_str);
cin >> Telefono_str;

cout << "Carga de Email" << endl;
proveedor.setEmail(Email_str);
cin >> Email_str;

cout << "Carga de Direccion" << endl;
proveedor.setDireccion(Direccion_str);
cin >> Direccion_str;
proveedor.setEstado(true);
Estado=true;                        /// -----> revisar


proveedor= Proveedores (idProv, CUIT_str, Nombre_str, Telefono_str, Email_str, Direccion_str,Estado);


if (ArchivodeProveedores.Guardar(proveedor)){

    cout<< "Se guardo correctamente!";
}
else{
    cout<<"Hubo un error al realizar la carga";

}

}



void Usuario_maestro::cargarCompras(){

string idCompra, idProv;
Fecha Hfecha;
int estado;
float Importe;

Compras compra;
ComprasArchivo Arch;

cout << "Carga ID de la compra" << endl;
cin.ignore();
getline(cin,idCompra);

cout << "Carga ID de Proveedor" << endl;
getline(cin,idProv);

cout << "Carga de Fecha" << endl;
Hfecha.Cargar();

cout << "Carga de Importe" << endl;
cin >> Importe;

cout<<"Ingresar OK=1, NO=0"<< endl;
cin>>estado;

compra= Compras (idCompra, idProv, Hfecha, Importe, estado);


if (Arch.guardar(compra)){

    cout<< "Se guardo correctamente!";
}
else{
    cout<<"Hubo un error al realizar la carga";

}

}

void listarProductos(){













/*
 ProductosArchivo pProductos;
 Productos registro;
 int cantidadRegistros;

  cantidadRegistros= pProductos.cantidadTotalProductos();

  for ( int i=0; i< cantidadRegistros; i++){

    registro = pProductos.leer(i);
  }
*/

}
