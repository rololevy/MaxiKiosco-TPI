#include <iostream>
using namespace std;
#include "MenuPrincipal.h"
#include "Usuario_maestro.h"


void MenuPrincipal::mostrar(){
 srand(time(0));
    int opcion;
    Usuario_maestro cargas;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Cargar Producto" << endl;
        cout << "2. Cargar Proveedor" << endl;
        cout << "3. Cargar Compra" << endl;
        cout << "4. Listados" << endl;
        cout << "5. Consultas" << endl;
        cout << "6. Informes" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opci¢n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cargas.cargarProducto();
                ;
                break;
            case 2:
                ;
                break;
            case 3:
                ;
                break;
            case 4:
                ;
                break;
            case 5:
                ;
                break;
            case 6:
                ;
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 0);

    }

