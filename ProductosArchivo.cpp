#include "ProductosArchivo.h"

ProductosArchivo::ProductosArchivo(){
 _nombreArchivo="ProductosArchivo.dat"
}

ProductosArchivo::ProductosArchivo(std::string nombreArchivo){
_nombreArchivo=nombreArchivo;

}

bool ProductosArchivo::guardar (Productos registro){
 bool seguardo;
 FILE *pFile;

 pFile = fopen (_nombreArchivo.c_str(), "ab");

 if (pFile== nullptr){
    return false;
 }

 seguardo =fwrite(&registro, sizeof(Productos), 1, pFile);

 fclose(pFile);

 return seguardo;
}

int ProductosArchivo::cantidadTotalProductos (){

int tamRegistro, total, cantidad;

FILE *pFile;

pFile = fopen (_nombreArchivo.c_str(), "rb");

if (pFile==nullptr){

    return 0;
}

fseek (pFile, 0, SEEK_END);
total=ftell (pFile);
cantidad = total / sizeof(Productos);

fclose (pFile);

return cantidad;


}
