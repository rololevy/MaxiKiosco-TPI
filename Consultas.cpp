#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
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
        cout << "1. Buscar proveedor por CUIT" << endl;
        cout << "2. Buscar proveedor por Telefono" << endl;
        cout << "3. Buscar proveedor por Email" << endl;
        cout << "4. Buscar proveedor por Direccion" << endl;
        cout << "5. Productos ordenados por Cantidad" << endl;
        cout << "6. Productos ordenados por Tipo" << endl;
        cout << "7. Productos ordenados por Precio" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                buscarProveedorPorCUIT();
                break;
            case 2:
                buscarProveedorPorTelefono();
                break;
            case 3:
                buscarProveedorPorEmail();
                break;
            case 4:
                buscarProveedorPorDireccion();
                break;
            case 5:
                productosOrdenadosPorCantidad();
                break;
            case 6:
                productosOrdenadosPorTipo();
                break;
            case 7:
                productosOrdenadosPorPrecio();
                break;
            case 0:
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
        if(opcion!=0) system("pause");
    } while (opcion != 0);
}

void Consultas::mostrarProveedoresActivos(){
ProveedorArchivo dat;
int cantidad = dat.getCantidadRegistros();

Proveedores *vecProveedores;

vecProveedores = new Proveedores [cantidad];

dat.leerMuchos(vecProveedores, cantidad);

for (int o=0; o<cantidad; o++){
if(vecProveedores[o].getEstado()==true){
    cout<< "=================================="<<endl;
    cout<<" PROVEEDOR ACTIVO :   "<<vecProveedores[o].getNombre()<<"||   TELEFONO    "<<vecProveedores[o].getTelefono()<<endl;

}

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

        if(vecProductos[o].getEstado()==true){

    cout<< "=================================="<<endl;
    cout<<" PRODUCTO ACTIVO :"<<vecProductos[o].getnombreProducto()<<" STOCK "<<vecProductos[o].getstock()<<endl;


}
}
delete [] vecProductos;
}

void Consultas::buscarProveedorPorCUIT(){
    string valor;
    cout << "CUIT a buscar: ";
    getline(cin, valor);
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    bool encontrado=false;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado() && valor==p.getCUIT()){
            p.Mostrar();
            encontrado=true;
        }
    }
    if(!encontrado) cout << "No se encontro proveedor" << endl;
}

void Consultas::buscarProveedorPorTelefono(){
    string valor;
    cout << "Telefono a buscar: ";
    getline(cin, valor);
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    bool encontrado=false;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado() && valor==p.getTelefono()){
            p.Mostrar();
            encontrado=true;
        }
    }
    if(!encontrado) cout << "No se encontro proveedor" << endl;
}

void Consultas::buscarProveedorPorEmail(){
    string valor;
    cout << "Email a buscar: ";
    getline(cin, valor);
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    bool encontrado=false;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado() && valor==p.getemail()){
            p.Mostrar();
            encontrado=true;
        }
    }
    if(!encontrado) cout << "No se encontro proveedor" << endl;
}

void Consultas::buscarProveedorPorDireccion(){
    string valor;
    cout << "Direccion a buscar: ";
    getline(cin, valor);
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    bool encontrado=false;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado() && valor==p.getDireccion()){
            p.Mostrar();
            encontrado=true;
        }
    }
    if(!encontrado) cout << "No se encontro proveedor" << endl;
}

void Consultas::productosOrdenadosPorCantidad(){
    ProductosArchivo arch;
    int cant = arch.cantidadTotalProductos();
    vector<Productos> vec;
    for(int i=0;i<cant;i++){
        Productos p = arch.leer(i);
        if(p.getEstado()) vec.push_back(p);
    }
    sort(vec.begin(), vec.end(),[](Productos a, Productos b){
        return a.getstock() > b.getstock();
    });
    for(auto &p : vec){
        arch.mostrarProductosActivos(p);
    }
}

void Consultas::productosOrdenadosPorTipo(){
    ProductosArchivo arch;
    int cant = arch.cantidadTotalProductos();
    vector<Productos> vec;
    for(int i=0;i<cant;i++){
        Productos p = arch.leer(i);
        if(p.getEstado()) vec.push_back(p);
    }
    sort(vec.begin(), vec.end(),[](Productos a, Productos b){
        return string(a.gettipoProducto()) < string(b.gettipoProducto());
    });
    for(auto &p : vec){
        arch.mostrarProductosActivos(p);
    }
}

void Consultas::productosOrdenadosPorPrecio(){
    ProductosArchivo arch;
    int cant = arch.cantidadTotalProductos();
    vector<Productos> vec;
    for(int i=0;i<cant;i++){
        Productos p = arch.leer(i);
        if(p.getEstado()) vec.push_back(p);
    }
    sort(vec.begin(), vec.end(),[](Productos a, Productos b){
        return a.getprecioUnitario() < b.getprecioUnitario();
    });
    for(auto &p : vec){
        arch.mostrarProductosActivos(p);
    }
}


