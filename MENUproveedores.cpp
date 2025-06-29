#include <iostream>
#include "MENUproveedores.h"
#include "Usuario_maestro.h"
using namespace std;





void MENUproveedores::Mostrar(){

Usuario_maestro Cargaprov;
int Opcion;
 do{
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Menu Proveedores     "<<endl;
        cout << "1. Cargar nuevo Proveedor"<<endl;
        cout << "2. Listado de Proveedores activos"<<endl;
        cout << "3. Eliminar Proveedor"<<endl;
        cout << "4. Modificar datos del Proveedor"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
          Cargaprov.cargarProveedor();
    break;

   case 2:
       Cargaprov.listarProveedores();
    break;

   case 3:
       Cargaprov.eliminarProveedores();
    break;

   case 4:
       Cargaprov.modificarProveedores();
    break;
   case 0:
        break;
    default:
        cout << "Elija una opcion valida:" << endl;

   }

}while (Opcion != 0);











}
