#include <iostream>
using namespace std;
#include "MENUProducto.h"
#include "Manager.h"
#include "Archivo.h"



void MENUProducto::mostrar (){
    Manager cargas;
int Opcion;
 do{
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Menu Producto     "<<endl;
        cout << "1. Cargar nuevo producto"<<endl;
        cout << "2. Listado de productos activos"<<endl;
        cout << "3. Eliminar producto"<<endl;
        cout << "4. Modificar datos del producto"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opci¢n:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
          cargas.cargarProducto();
    break;

   case 2:
       cargas.listarProductos();
    break;

   case 3:
       cargas.eliminarProducto();
    break;

   case 4:
       cargas.modificarProducto();
    break;

   case 5:

    break;

    default:
        cout << "Elija una opcion valida:" << endl;

   }

}while (Opcion != 0);
}



 /*posicion2=registro.buscarNombre(nombreProducto);
                if (posicion2 >=0){
                    prodCarga2=registro.leer(posicion2);
                    cout <<"Ingrese Nombre del nuevo Producto";
                    cin.ignore();
                    getline(cin, nombreProducto);
                }
                prodCarga2.setnombreProducto(nombreProducto);
                if (registro.Guardar(prodCarga2, posicion2)){
                    cout<<"Registro moficicado correctamente"<<endl;
                }
                else {
                    cout<<"No se pudo moficar el registro"<<endl;
                }
*/
