#pragma once
#include <string>

class Productos {

private:
    char _IDProducto[10];
    char _nombreProducto[15];
    char _tipoProducto[15];
    float _precioUnitario;
    int _stock;
    bool _estado=true;

public:
    Productos ();
    Productos(std::string IDProducto, std::string nombreProducto, std::string tipoProducto, float precio, int stock);

    std::string getIDProducto();
    std::string getnombreProducto();
    std::string gettipoProducto();
    float getprecioUnitario();
    int getstock();
    bool getEstado();

    void setIDProducto(std::string IDProducto);
    void setnombreProducto(std::string nombre);
    void settipoProducto(std::string tipo);
    void setprecioUnitario(float precio);
    void setstock(int stock);
    void setEstado (bool estado);
    std::string toCSV();

    void cargar();
    void mostrar();
    void eliminar();
};

