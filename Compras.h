#pragma once
#include "Fecha.h"
#include <iostream>

class Compras {
private:
    char idProveedor[30];
    char idCompra[30];
    Fecha _fecha;
    float importe;
    bool activo;

public:
    // Constructor por defecto
    Compras();
    Compras(string IDcompra,string idPROV,Fecha fecha,float Importe, int estado);   /// para informes

    // Getters
    const char* getIdProveedor();
    const char* getIdCompra();
    Fecha getFecha();
    float getImporte();
    bool getActivo();

    // Setters
    void setIdProveedor(const char* id);
    void setIdCompra(const char* id);
    void setFecha(const Fecha& fecha);
    void setImporte(float importe);
    void setActivo(bool estado);

    // Métodos útiles
    void mostrar();
};
