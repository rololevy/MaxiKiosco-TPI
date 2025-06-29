#include <iostream>
#include "Listados.h"
#include "ProveedorArchivo.h"
#include "ProductosArchivo.h"
#include "ComprasArchivo.h"

using namespace std;

void Listados::MENUlistados(){
    int Opcion;
    do{
        cout<<"---------------------------------------------------"<<endl;
        cout << "      Menu Listados     "<<endl;
        cout << "1. Listado de Proveedores"<<endl;
        cout << "2. Listado Productos"<<endl;
        cout << "3. Listado Compras"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion:  ";
        cin >> Opcion;

        switch(Opcion){
            case 1:
                Menu1();
                break;
            case 2:
                Menu2();
                break;
            case 3:
                Menu3();
                break;
            case 0:
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
    }while (Opcion != 0);
}

void Listados::Menu1(){
    ProveedorArchivo arch;
    if(arch.listarTodos()==0){
        cout << "No hay proveedores para mostrar" << endl;
    }
}

void Listados::Menu2(){
    ProductosArchivo arch;
    arch.listarProductos();
}

void Listados::Menu3(){
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    for(int i=0;i<cant;i++){
        Compras dato = arch.leerUno(i);
        if(dato.getActivo()){
            cout << "======================================" << endl;
            dato.mostrar();
        }
    }
}
