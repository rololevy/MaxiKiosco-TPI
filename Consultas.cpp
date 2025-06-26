#include <iostream>
using namespace std;
#include "Consultas.h"
#include "ProductosArchivo.h"
#include "ProveedorArchivo.h"

Consultas::Consultas(){
};


void Consultas::menuconsultas(){

    int opcion;

    do {
        cout << "\n--- Menu Consultas ---" << endl;
        cout << "1. Mostrar Proveedores activos" << endl;
        cout << "2. Mostrar Productos activos" << endl;
        cout << "--------------" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opci¢n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
               mostrarProveedoresActivos();

                break;
            case 2:
               mostrarProductosActivos();
                ;
                break;
            case 3:
                ;
                break;

            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 0);

    }

void Consultas::mostrarProveedoresActivos(){
ProveedorArchivo dat;
int cantidad = dat.getCantidadRegistros();

Proveedores *vecProveedores;

vecProveedores = new Proveedores [cantidad];

dat.leerMuchos(vecProveedores, cantidad);

for (int o=0; o<cantidad; o++){

    cout<< "=================================="<<endl;
    cout<<" PROVEEDOR ACTIVO :   "<<vecProveedores[o].getNombre()<<"||   TELEFONO    "<<vecProveedores[o].getTelefono()<<endl;

}

}
///****************************************************************************************************************************

void Consultas::mostrarProductosActivos(){
ProductosArchivo dat;
int cantidad = dat.cantidadTotalProductos();

Productos *vecProductos;

vecProductos = new Productos [cantidad];

dat.leerMuchos(vecProductos, cantidad);

for (int o=0; o<cantidad; o++){

    cout<< "=================================="<<endl;
    cout<<" PRODUCTO ACTIVO :"<<vecProductos[o].getnombreProducto()<<" STOCK "<<vecProductos[o].getstock();


}




}

