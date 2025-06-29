#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
#include "Consultas.h"
#include "ProductosArchivo.h"
#include "ProveedorArchivo.h"
#include <limits>
#include <vector>
#include <algorithm>

Consultas::Consultas(){
};


void Consultas::menuconsultas(){
    int opcion;
    do {
        cout << "\n--- Menu Consultas ---" << endl;
        cout << "1. Proveedor por CUIT" << endl;
        cout << "2. Proveedor por Telefono" << endl;
        cout << "3. Proveedor por Email" << endl;
        cout << "4. Proveedor por Direccion" << endl;
        cout << "5. Productos por Cantidad" << endl;
        cout << "6. Productos por Tipo" << endl;
        cout << "7. Productos por Precio" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcin: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(opcion){
            case 1: consultarProveedorPorCUIT(); break;
            case 2: consultarProveedorPorTelefono(); break;
            case 3: consultarProveedorPorEmail(); break;
            case 4: consultarProveedorPorDireccion(); break;
            case 5: listarProductosPorCantidad(); break;
            case 6: listarProductosPorTipo(); break;
            case 7: listarProductosPorPrecio(); break;
        }
    } while(opcion != 0);
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




void Consultas::consultarProveedorPorCUIT(){
    string cuit;
    cout << "Ingrese CUIT: ";
    getline(cin, cuit);
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    bool encontrado=false;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado() && p.getCUIT()==cuit){
            p.Mostrar();
            encontrado=true;
        }
    }
    if(!encontrado) cout << "No se encontro proveedor" << endl;
}

void Consultas::consultarProveedorPorTelefono(){
    string tel;
    cout << "Ingrese Telefono: ";
    getline(cin, tel);
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    bool encontrado=false;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado() && p.getTelefono()==tel){
            p.Mostrar();
            encontrado=true;
        }
    }
    if(!encontrado) cout << "No se encontro proveedor" << endl;
}

void Consultas::consultarProveedorPorEmail(){
    string email;
    cout << "Ingrese Email: ";
    getline(cin, email);
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    bool encontrado=false;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado() && p.getemail()==email){
            p.Mostrar();
            encontrado=true;
        }
    }
    if(!encontrado) cout << "No se encontro proveedor" << endl;
}

void Consultas::consultarProveedorPorDireccion(){
    string dir;
    cout << "Ingrese Direccion: ";
    getline(cin, dir);
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    bool encontrado=false;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado() && p.getDireccion()==dir){
            p.Mostrar();
            encontrado=true;
        }
    }
    if(!encontrado) cout << "No se encontro proveedor" << endl;
}

void Consultas::listarProductosPorCantidad(){
    ProductosArchivo arch;
    int cant = arch.cantidadTotalProductos();
    vector<Productos> vec;
    for(int i=0;i<cant;i++){
        Productos pr = arch.leer(i);
        if(pr.getEstado()) vec.push_back(pr);
    }
    sort(vec.begin(), vec.end(), [](Productos a, Productos b){
        return a.getstock() > b.getstock();
    });
    for(auto &p: vec){
        arch.mostrarProductosActivos(p);
    }
}

void Consultas::listarProductosPorTipo(){
    ProductosArchivo arch;
    int cant = arch.cantidadTotalProductos();
    vector<Productos> vec;
    for(int i=0;i<cant;i++){
        Productos pr = arch.leer(i);
        if(pr.getEstado()) vec.push_back(pr);
    }
    sort(vec.begin(), vec.end(), [](Productos a, Productos b){
        return a.gettipoProducto() < b.gettipoProducto();
    });
    for(auto &p: vec){
        arch.mostrarProductosActivos(p);
    }
}

void Consultas::listarProductosPorPrecio(){
    ProductosArchivo arch;
    int cant = arch.cantidadTotalProductos();
    vector<Productos> vec;
    for(int i=0;i<cant;i++){
        Productos pr = arch.leer(i);
        if(pr.getEstado()) vec.push_back(pr);
    }
    sort(vec.begin(), vec.end(), [](Productos a, Productos b){
        return a.getprecioUnitario() < b.getprecioUnitario();
    });
    for(auto &p: vec){
        arch.mostrarProductosActivos(p);
    }
}

