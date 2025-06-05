#pragma once
#include <string>

class Productos {

private:
    char _IDProducto[10];
    char _nombreProducto[50];
    char _tipoProducto[30];
    float _precioUnitario;
    int _stock;
    bool _estado;

public:
    int getIDProducto();
    const char* getnombreProducto();
    const char* gettipoProducto();
    float getprecioUnitario();
    int getstock();

    void setIDProducto(int ID);
    void setnombreProducto(std::string nombre);
    void settipoProducto(std::string tipo);
    void setprecioUnitario(float precio);
    void setstock(int stock);

    void cargar();
    void mostrar();
    void eliminar();
};

