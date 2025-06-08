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
    Producto ();
    Producto(std::string IDProducto, std::string nombreProducto, std::string tipoProducto, float precio, int stock, bool estado);
    
    int getIDProducto();
    std::string getnombreProducto();
    std::string gettipoProducto();
    float getprecioUnitario();
    int getstock();
    bool getEstado();

    void setIDProducto(int ID);
    void setnombreProducto(std::string nombre);
    void settipoProducto(std::string tipo);
    void setprecioUnitario(float precio);
    void setstock(int stock);
    void setEstado (bool estado);

    void cargar();
    void mostrar();
    void eliminar();
};

