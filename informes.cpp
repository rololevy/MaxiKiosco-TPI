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
#include <map>
#include <vector>
#include <algorithm>

void informes::mostrarMenu(){
    int opcion;

    do {
        system("cls");
        cout << "--- Menu Informes ---" << endl;
        cout << "1. Producto con mas stock" << endl;
        cout << "2. Producto con menos stock" << endl;
        cout << "3. Compras por mes" << endl;
        cout << "4. Productos con stock bajo" << endl;
        cout << "5. Cantidad productos activos/inactivos" << endl;
        cout << "6. Total gastado por mes" << endl;
        cout << "7. Proveedor con mas compras" << endl;
        cout << "8. Top 3 proveedores mas frecuentes" << endl;
        cout << "9. Cantidad proveedores activos/inactivos" << endl;
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
            case 4:{
                int umbral;
                cout << "INGRESE EL UMBRAL DE STOCK BAJO: ";
                cin >> umbral;
                if(umbral <= 0) umbral = 5;
                productosStockBajo(umbral);
                system("pause");
                break;
            }
            case 5:
                cantidadProductosActivosInactivos();
                break;
            case 6:
                totalGastadoPorMes();
                break;
            case 7:
                proveedorMasCompras();
                break;
            case 8:
                top3ProveedoresMasFrecuentes();
                break;
            case 9:
                cantidadProveedoresActivosInactivos();
                break;
            case 0:
                return;
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 0);
}

void informes::productosStockBajo(int umbral){
    ProductosArchivo archProd;
    Productos prod;
    int cant = archProd.cantidadTotalProductos();
    cout << "PRODUCTOS CON STOCK MENOR A " << umbral << endl;
    for(int i=0; i<cant; i++){
        prod = archProd.leer(i);
        if(prod.getEstado() && prod.getstock() < umbral){
            archProd.mostrarProductosActivos(prod);
        }
    }
}

void informes::cantidadProductosActivosInactivos(){
    ProductosArchivo archProd;
    Productos prod;
    int cant = archProd.cantidadTotalProductos();
    int activos = 0, inactivos = 0;
    for(int i=0; i<cant; i++){
        prod = archProd.leer(i);
        if(prod.getEstado()) activos++; else inactivos++;
    }
    cout << "Productos activos: " << activos << endl;
    cout << "Productos dados de baja: " << inactivos << endl;
}

void informes::totalGastadoPorMes(){
    ComprasArchivo arch;
    int anio, mes;
    cout << "INGRESE EL ANIO: ";
    cin >> anio;
    cout << "INGRESE EL MES (1-12): ";
    cin >> mes;
    int cant = arch.getCantidadRegistros();
    Compras comp;
    float total = 0;
    for(int i=0; i<cant; i++){
        comp = arch.leerUno(i);
        if(comp.getActivo() && comp.getFecha().getAnio()==anio && comp.getFecha().getMes()==mes){
            total += comp.getImporte();
        }
    }
    cout << "TOTAL GASTADO EN " << mes << "/" << anio << ": $" << total << endl;
}

void informes::proveedorMasCompras(){
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    Compras comp;
    std::map<std::string,int> cantProv;
    std::map<std::string,float> montoProv;
    for(int i=0; i<cant; i++){
        comp = arch.leerUno(i);
        if(!comp.getActivo()) continue;
        std::string id = comp.getIdProveedor();
        cantProv[id]++;
        montoProv[id] += comp.getImporte();
    }
    if(cantProv.empty()){
        cout << "No hay compras registradas" << endl;
        return;
    }
    std::string idMaxCant; int maxCant = -1;
    for(auto &p : cantProv){
        if(p.second > maxCant){
            maxCant = p.second;
            idMaxCant = p.first;
        }
    }
    std::string idMaxMonto; float maxMonto = -1;
    for(auto &p : montoProv){
        if(p.second > maxMonto){
            maxMonto = p.second;
            idMaxMonto = p.first;
        }
    }
    cout << "Proveedor con mas compras (cantidad): " << idMaxCant << " - " << maxCant << " compras" << endl;
    cout << "Proveedor con mas compras (monto): " << idMaxMonto << " - $" << maxMonto << endl;
}

void informes::top3ProveedoresMasFrecuentes(){
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    Compras comp;
    std::map<std::string,int> cantProv;
    for(int i=0; i<cant; i++){
        comp = arch.leerUno(i);
        if(comp.getActivo()) cantProv[comp.getIdProveedor()]++;
    }
    std::vector<std::pair<std::string,int>> vec(cantProv.begin(), cantProv.end());
    std::sort(vec.begin(), vec.end(), [](const std::pair<std::string,int>& a, const std::pair<std::string,int>& b){
        return a.second > b.second;
    });
    cout << "TOP 3 PROVEEDORES MAS FRECUENTES" << endl;
    for(size_t i=0; i<vec.size() && i<3; i++){
        cout << i+1 << ". " << vec[i].first << " - " << vec[i].second << " compras" << endl;
    }
}

void informes::cantidadProveedoresActivosInactivos(){
    FILE* archivo = fopen("Proveedores.dat", "rb");
    if(archivo == nullptr){
        cout << "No se pudo abrir el archivo de proveedores" << endl;
        return;
    }
    Proveedores prov;
    int act=0, inact=0;
    while(fread(&prov, sizeof(Proveedores), 1, archivo)==1){
        if(prov.getEstado()) act++; else inact++;
    }
    fclose(archivo);
    cout << "Proveedores activos: " << act << endl;
    cout << "Proveedores inactivos: " << inact << endl;
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
        else if(objProd.getstock() < menosStock){
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
    do {
        system("cls");
        cout << "--- Menu Listados ---" << endl;
        cout << "1. Proveedores por ID" << endl;
        cout << "2. Proveedores por Nombre" << endl;
        cout << "3. Productos por ID" << endl;
        cout << "4. Productos por Nombre" << endl;
        cout << "5. Compras por Proveedor" << endl;
        cout << "6. Compras por Fecha" << endl;
        cout << "7. Compras por Importe" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
            case 1:
                listarProveedoresPorID();
                break;
            case 2:
                listarProveedoresPorNombre();
                break;
            case 3:
                listarProductosPorID();
                break;
            case 4:
                listarProductosPorNombre();
                break;
            case 5:
                listarComprasPorProveedor();
                break;
            case 6:
                listarComprasPorFecha();
                break;
            case 7:
                listarComprasPorImporte();
                break;
            case 0:
                return;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
        system("pause");
    } while(opcion != 0);
}

void informes::listarProveedoresPorID(){
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    std::vector<Proveedores> vec;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado()) vec.push_back(p);
    }
    std::sort(vec.begin(), vec.end(),[](Proveedores a, Proveedores b){
        return a.getidProveedor() < b.getidProveedor();
    });
    for(auto &p : vec){
        p.Mostrar();
        cout << "----------------------" << endl;
    }
}

void informes::listarProveedoresPorNombre(){
    ProveedorArchivo arch;
    int cant = arch.getCantidadRegistros();
    std::vector<Proveedores> vec;
    for(int i=0;i<cant;i++){
        Proveedores p = arch.leerUno(i);
        if(p.getEstado()) vec.push_back(p);
    }
    std::sort(vec.begin(), vec.end(),[](Proveedores a, Proveedores b){
        return std::string(a.getNombre()) < std::string(b.getNombre());
    });
    for(auto &p : vec){
        p.Mostrar();
        cout << "----------------------" << endl;
    }
}

void informes::listarProductosPorID(){
    ProductosArchivo arch;
    int cant = arch.cantidadTotalProductos();
    std::vector<Productos> vec;
    for(int i=0;i<cant;i++){
        Productos pr = arch.leer(i);
        if(pr.getEstado()) vec.push_back(pr);
    }
    std::sort(vec.begin(), vec.end(),[](Productos a, Productos b){
        return a.getIDProducto() < b.getIDProducto();
    });
    for(auto &p : vec){
        arch.mostrarProductosActivos(p);
    }
}

void informes::listarProductosPorNombre(){
    ProductosArchivo arch;
    int cant = arch.cantidadTotalProductos();
    std::vector<Productos> vec;
    for(int i=0;i<cant;i++){
        Productos pr = arch.leer(i);
        if(pr.getEstado()) vec.push_back(pr);
    }
    std::sort(vec.begin(), vec.end(),[](Productos a, Productos b){
        return a.getnombreProducto() < b.getnombreProducto();
    });
    for(auto &p : vec){
        arch.mostrarProductosActivos(p);
    }
}

void informes::listarComprasPorProveedor(){
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    std::vector<Compras> vec;
    for(int i=0;i<cant;i++){
        Compras c = arch.leerUno(i);
        if(c.getActivo()) vec.push_back(c);
    }
    std::sort(vec.begin(), vec.end(),[](Compras a, Compras b){
        return std::string(a.getIdProveedor()) < std::string(b.getIdProveedor());
    });
    for(auto &c : vec){
        c.mostrar();
    }
}

void informes::listarComprasPorFecha(){
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    std::vector<Compras> vec;
    for(int i=0;i<cant;i++){
        Compras c = arch.leerUno(i);
        if(c.getActivo()) vec.push_back(c);
    }
    std::sort(vec.begin(), vec.end(),[](Compras a, Compras b){
        if(a.getFecha().getAnio()!=b.getFecha().getAnio())
            return a.getFecha().getAnio()<b.getFecha().getAnio();
        if(a.getFecha().getMes()!=b.getFecha().getMes())
            return a.getFecha().getMes()<b.getFecha().getMes();
        return a.getFecha().getDia()<b.getFecha().getDia();
    });
    for(auto &c : vec){
        c.mostrar();
    }
}

void informes::listarComprasPorImporte(){
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    std::vector<Compras> vec;
    for(int i=0;i<cant;i++){
        Compras c = arch.leerUno(i);
        if(c.getActivo()) vec.push_back(c);
    }
    std::sort(vec.begin(), vec.end(),[](Compras a, Compras b){
        return a.getImporte() < b.getImporte();
    });
    for(auto &c : vec){
        c.mostrar();
    }
}


