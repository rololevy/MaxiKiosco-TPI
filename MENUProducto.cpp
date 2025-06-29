#include <iostream>
#include <limits>
using namespace std;
#include "MENUProducto.h"
#include "Usuario_maestro.h"
#include "ProductosArchivo.h"
#include <limits>



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
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Elija una opci¢n:  ";
  cin >> Opcion;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
