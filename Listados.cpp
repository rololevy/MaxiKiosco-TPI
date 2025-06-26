#include <iostream>
#include "Listados.h"
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


void Menu1();
void Menu2();
void Menu3(){


FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    int TotalActivos[100]={};
    if (archivo == nullptr) return 0;
    Compras Dato;
    while (fread(&Dato, sizeof(Compras), 1, archivo)) {
        if (Dato.getActivo()) {
           cout << "======================================" << endl;
            Dato.mostrar();
            TotalActivos[i]=;
        }
    }
    fclose(archivo);


}



/*void Orden_ProveedoresID(){

Proveedores Usu;
ProveedorArchivo Archi;

int Totalreg= Archi.getCantidadRegistros();

for(int i=0 ; i<Totalreg; i++){
        Usu = Archi.leerUno(i);
if(Usu.getidProveedor())

    }



}*/















