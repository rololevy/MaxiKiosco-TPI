#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

#include "informes.h"
#include "Productos.h"
#include "ProductosArchivo.h"
#include "Compras.h"
#include "ComprasArchivo.h"
#include "ProveedorArchivo.h"

void informes::mostrarMenu(){
    int opcion;

    do {
        system("cls");
        cout << "--- Menu Informes ---" << endl;
        cout << "1. Producto con mas stock" << endl;
        cout << "2. Producto con menos stock" << endl;
        cout << "3. Compras por mes" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1:
                productosConMasStock();
                break;
            case 2:
                productosConMenosStock();
                break;
            case 3:
                comprasPorMes();
                break;
            case 0:
                return;
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 0);
}

void informes::productosConMasStock(){
    Productos objProd;
    ProductosArchivo archProd;

    int cantReg = archProd.cantidadTotalProductos();
    int maxStock = -1;
    string nombreProdMax;
    for(int i=0 ; i<cantReg; i++){
        objProd = archProd.leer(i);

        if(objProd.getstock()>maxStock){
            maxStock=objProd.getstock();
            nombreProdMax = objProd.getnombreProducto();
        }
    }

    cout<<"==============================================="<<endl;
    cout<<"EL PRODUCTO CON MAS STOCK ES : "<<nombreProdMax<<endl;
    cout<<"STOCK : "<<maxStock<<endl;
    cout<<"==============================================="<<endl;
}

void informes::productosConMenosStock(){
    Productos objProd;
    ProductosArchivo archProd;

    int cantReg = archProd.cantidadTotalProductos();
    int menosStock;
    string nombreProdMin;
    bool band=true;

    for(int i=0 ; i<cantReg; i++){
        objProd = archProd.leer(i);

        if(band){
            menosStock = objProd.getstock();
            nombreProdMin = objProd.getnombreProducto();
            band = false;
        }
        else if(menosStock<objProd.getstock()){
            menosStock = objProd.getstock();
            nombreProdMin = objProd.getnombreProducto();
        }
    }

    cout<<"==============================================="<<endl;
    cout<<"EL PRODUCTO CON MENOS STOCK ES : "<<nombreProdMin<<endl;
    cout<<"STOCK : "<<menosStock<<endl;
    cout<<"==============================================="<<endl;
}

void informes::comprasPorMes(){
    Compras objCompras;
    ComprasArchivo archCompras;

    bool compraAnio = false , compraMes = false;

    int anio , mes;

    cout<<"INGRESE EL ANIO QUE DESEA BUSCAR: ";
    cin>>anio;
    cout<<"INGRESE EL MES (1 - 12) : ";
    cin>>mes;

    int cantReg = archCompras.getCantidadRegistros();

    for(int i=0 ; i<cantReg ; i++){
        objCompras = archCompras.leerUno(i);

        if(objCompras.getFecha().getAnio() == anio){
            compraAnio = true;
            if(objCompras.getFecha().getMes()== mes){
                compraMes = true;
                objCompras.mostrar();
                cout<<"==================="<<endl;
            }
        }

    }

    if(!compraAnio){
        cout<<"EN EL ANIO "<<anio<<" NO SE REGISTRAN VENTAS"<<endl;
        return;
    }
    if(!compraMes){
        cout<<"EN EL MES "<<mes<<" NO SE REGISTRAN VENTAS"<<endl;
        return;
    }


}


void informes::Listardatos(){
    int opcion;
    ProveedorArchivo Arch;
    Proveedores Prov;

    Productos productos;
    ProductosArchivo ArchProductos;

    Compras compra;
    ComprasArchivo ArchivoCompras;

    do {
        system("cls");
        cout << "--- Menu Listas ---" << endl;
        cout << "1. Listar Productos" << endl;
        cout << "2. Listar Proveedores" << endl;
        cout << "3. Listar Compras" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1:{
            int Cantreg= ArchProductos.cantidadTotalProductos();   /// cuento y guardo cantidad de registros

            if(Cantreg==0){
            cout << "No hay productos registrados" << endl;
            }
            int RegistroProductos=ArchProductos.listarTodos();       ///muestra los archivos activos(true)
                system("pause");

                break;}
            case 2:{
                int Cantreg= Arch.getCantidadRegistros();

                if(Cantreg==0){
                 cout << "No hay proveedores registrados" << endl;

                }

                int registrosCargados=Arch.listarTodos();

                system("pause");
                break;}
            case 3:{
                int Cantreg= ArchivoCompras.getCantidadRegistros();

                if(Cantreg==0){
                 cout << "No hay compras registradas" << endl;

                }

                int registrosCargados=ArchivoCompras.listarTodos();

                system("pause");
                break;}
            case 0:
                return;
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 0);
}


