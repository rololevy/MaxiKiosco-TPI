#include <iostream>
using namespace std;
#include "MenuPrincipal.h"


void MenuPrincipal::mostrar(){
 srand(time(0));
    int opcion;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Cargar" << endl;
        cout << "2. Listados" << endl;
        cout << "3. Consultas" << endl;
        cout << "4. Informes" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opci¢n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
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
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 5);

    }

