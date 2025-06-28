#include <iostream>
using namespace std;
#include "MenuPrincipal.h"
#include "MENUProducto.h"
#include "informes.h"
#include "Usuario_maestro.h"


void MenuPrincipal::mostrar(){

    int opcion;
    MENUProducto menuProd;
    Usuario_maestro abm;
    informes inf;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Productos" << endl;
        cout << "2. Cargar Proveedor" << endl;
        cout << "3. Cargar Compra" << endl;
        cout << "4. Listados" << endl;
        cout << "5. Consultas" << endl;
        cout << "6. Informes" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcin: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuProd.mostrar();
                break;
            case 2:
                abm.cargarProveedor();
                break;
            case 3:
                abm.cargarCompras();
                break;
            case 4:
                inf.Listardatos();
                break;
            case 5:
                // Menu de consultas pendiente
                break;
            case 6:
                inf.mostrarMenu();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 0);

    }
