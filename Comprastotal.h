#pragma once
#include <string>

class Comprastotal {
private:
    char idProducto[30];
    char idCompra[30];
    int cantidad;
    float importe;

public:
    Comprastotal();  // Constructor por defecto
    Comprastotal(std::string idProd, std::string idComp, int cant, float imp); // Constructor con parámetros

    std::string getIDProducto();
    std::string getIDCompra();
    int getCantidad();
    float getImporte();

    void setIDProducto(std::string idProd);
    void setIDCompra(std::string idComp);
    void setCantidad(int cant);
    void setImporte(float imp);

    void cargar();
    void mostrar();
};
