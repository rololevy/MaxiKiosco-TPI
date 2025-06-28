#include <iostream>
using namespace std;
#include "MENUProducto.h"
#include "Usuario_maestro.h"
#include "ProductosArchivo.h"



void MENUProducto::mostrar (){
    Usuario_maestro cargas;
int Opcion;
 do{
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Menu Producto     "<<endl;
        cout << "1. Cargar nuevo producto"<<endl;
        cout << "2. Eliminar producto"<<endl;
        cout << "3. Modificar datos del producto"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opci¢n:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
          cargas.cargarProducto();
    break;

   case 2:
       cargas.eliminarProducto();
    break;

   case 3:
       cargas.modificarProducto();
    break;

   default:
        cout << "Elija una opcion valida:" << endl;

   }

}while (Opcion != 0);

}
