#include "ComprasArchivo.h"
#include <iostream>
#include <cstdio>
using namespace std;

ComprasArchivo::ComprasArchivo(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

Compras ComprasArchivo::leerUno(int pos) {
    Compras maxi;
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "Error al abrir archivo para lectura" << endl;
        return maxi;
    }
    fseek(archivo, sizeof(Compras) * pos, SEEK_SET);
    fread(&maxi, sizeof(Compras), 1, archivo);
    fclose(archivo);
    return maxi;
}

bool ComprasArchivo::guardar(Compras maxi) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "ab");
    if (archivo == nullptr) return false;
    bool exito = fwrite(&maxi, sizeof(Compras), 1, archivo);
    fclose(archivo);
    return exito;
}

bool ComprasArchivo::modificar(Compras maxi, int pos) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (archivo == nullptr) return false;
    fseek(archivo, sizeof(Compras) * pos, SEEK_SET);
    bool exito = fwrite(&maxi, sizeof(Compras), 1, archivo);
    fclose(archivo);
    return exito;
}

bool ComprasArchivo::eliminar(Compras maxi, int pos) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (archivo == nullptr) return false;
    // Se supone que Compras tiene un método setActivo(false);
    maxi.setActivo(false);
    fseek(archivo, sizeof(Compras) * pos, SEEK_SET);
    bool exito = fwrite(&maxi, sizeof(Compras), 1, archivo);
    fclose(archivo);
    return exito;
}

void ComprasArchivo::listarTodos() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == nullptr) return;
    Compras maxi;
    while (fread(&maxi, sizeof(Compras), 1, archivo)) {
        if (maxi.getActivo()) {
            maxi.mostrar();  // Suponiendo que tiene un método mostrar()
        }
    }
    fclose(archivo);
}

int ComprasArchivo::getCantidadRegistros() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == nullptr) return 0;
    fseek(archivo, 0, SEEK_END);
    int cant = ftell(archivo) / sizeof(Compras);
    fclose(archivo);
    return cant;
}
