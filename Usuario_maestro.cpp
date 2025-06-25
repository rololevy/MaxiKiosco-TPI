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

    Productos prodCarga;
    ProductosArchivo registro;

string IDProducto, nombreProducto, tipoProducto;
float precioUnitario;
int stock;
bool estado;
IDProducto=registro.getNuevoID();
////aca se valida


cout <<"ID Producto"<<IDProducto<<endl;


cout << "Ingrese Nombre Producto"<< endl;
cin.ignore();
getline(cin, nombreProducto);

cout <<"Ingrese tipo de producto"<< endl;
getline(cin, tipoProducto);

cout << "Ingrese precio Unitario"<< endl;
cin>> precioUnitario;

cout<<"Ingrese stock"<< endl;
cin>> stock;




prodCarga= Productos(IDProducto, nombreProducto, tipoProducto, precioUnitario, stock);


if (registro.Guardar(prodCarga)){

    cout<< "Se guardo correctamente!"<<endl;
}
else{
    cout<<"Hubo un error al realizar la carga"<<endl;

}
}

void Usuario_maestro::listarProductos(){
Usuario_maestro mostrarEnLista;
 ProductosArchivo pProductos;
 Productos registro;

 int cantidadRegistros;

  cantidadRegistros= pProductos.cantidadTotalProductos();
if (cantidadRegistros>0){
    for ( int i=0; i< cantidadRegistros; i++){

    registro=pProductos.leer(i);

    mostrarEnLista.mostrarProductosActivos(registro);


  }


}
 else {
        cout<<"No hay registros para mostrar..."<<endl;
    }

}

void Usuario_maestro::mostrarProductosActivos(Productos registro){
bool reg=registro.getEstado();

if(reg){
cout<<"**************************************************"<<endl;
cout << "ID Producto : " <<registro.getIDProducto() << endl;
cout << "Nombre Producto : " << registro.getnombreProducto() << endl;
cout << "Tipo Producto : " << registro.gettipoProducto() << endl;
cout << "Precio Unitario $: " << registro.getprecioUnitario() << endl;
cout << "Stock : " << registro.getstock()<< endl;
cout<<"**************************************************"<<endl;
}


}

void Usuario_maestro::eliminarProducto (){

    Usuario_maestro cargas;
    ProductosArchivo registro;
    Productos setter;

    string idProducto;


 int posicion1;
cout<<"Ingrese ID Producto a eliminar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion1=registro.buscarProducto(idProducto);

    if (posicion1>=0){
        setter.setEstado(false);
        if (registro.Guardar(setter, posicion1)){
            cout<<"Registro eliminado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al eliminar el registro..."<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado... vuelva prontos"<<endl;
    }
    }


void Usuario_maestro::modificarProducto (){

    ProductosArchivo registro;

   string idProducto, nombreProducto, tipoProducto;
    float precioUnitario;
    int stock;



int Opcion;

 do{
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Que registro desea modificar     "<<endl;
        cout << "1. ID Producto"<<endl;
        cout << "2. Nombre Producto"<<endl;
        cout << "3. Tipo Producto"<<endl;
        cout << "4. Precio unitario"<<endl;
        cout << "5. Stock"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opci¢n:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
        int posicion;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion=registro.buscarProducto(idProducto);

    if (posicion>=0){
            Productos setter= registro.leer(posicion);
            cout<<"Ingrese el nuevo ID :"<<endl;
            getline(cin, idProducto);
            setter.setIDProducto(idProducto);

        if (registro.Guardar(setter, posicion)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }



    break;

   case 2:

         int posicion2;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion2=registro.buscarProducto(idProducto);

    if (posicion2>=0){
            Productos setter= registro.leer(posicion2);
            cout<<"Ingrese el nuevo nombre :"<<endl;
            getline(cin, nombreProducto);
            setter.setnombreProducto(nombreProducto);

        if (registro.Guardar(setter, posicion2)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }



    break;

   case 3:
        int posicion3;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion3=registro.buscarProducto(idProducto);

    if (posicion3>=0){
            Productos setter= registro.leer(posicion3);
            cout<<"Ingrese el nuevo tipo de producto :"<<endl;
            getline(cin, tipoProducto);
            setter.settipoProducto(tipoProducto);

        if (registro.Guardar(setter, posicion)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }


    break;

   case 4:
        int posicion4;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion4=registro.buscarProducto(idProducto);

    if (posicion4>=0){
            Productos setter= registro.leer(posicion4);
            cout<<"Ingrese el nuevo precio unitario :"<<endl;
            cin>>precioUnitario;
            setter.setprecioUnitario(precioUnitario);

        if (registro.Guardar(setter, posicion4)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }


    break;

   case 5:
         int posicion5;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion5=registro.buscarProducto(idProducto);

    if (posicion5>=0){
            Productos setter= registro.leer(posicion5);
            cout<<"Ingrese el nuevo Stock del producto :"<<endl;
            cin>>stock;
            setter.setstock(stock);

        if (registro.Guardar(setter, posicion5)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }


    break;

    default:
        cout << "Elija una opcion valida:" << endl;


}

}while (Opcion != 0);

}



///********************************************************************************************************************************************************

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


if (ArchivodeProveedores.Guardar(proveedor)){       /// guardo los datos en Proveedores.dat

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


