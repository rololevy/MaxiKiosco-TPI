#include "ProductosArchivo.h"

ProductosArchivo::ProductosArchivo(){
 _nombreArchivo="ProductosArchivo.dat"
}

ProductosArchivo::ProductosArchivo(std::string nombreArchivo){
_nombreArchivo=nombreArchivo;

}

bool ProductosArchivo::Guardar (Productos registro){
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

Productos ProductosArchivo::leer(int pos){

FILE *pFile;

 Productos reg;

 pFile= fopen (_nombreArchivo.c_str(), "rb");

 if (pFile == nullptr){

    return reg;
 }
 fseek (pFile, sizeof (Productos)*pos, SEEK_SET);

 fread(&reg, sizeof(Productos), 1 , pFile);

 fclose(pFile);
 return reg;

}

 bool ProductosArchivo::Modificar (Productos mod, int pos){
 FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
 if(pFile==NULL){
    return false;
 }
 fseek(pFile,sizeof(ProductosArchivo)* pos,SEEK_SET);
 bool Modif = fwrite(&mod,sizeof(ProductosArchivo),1,pFile);
 fclose(pFile);
 return Modif;


 }

 /// bool ProductosArchivo::Eliminar (Productos mod, int pos){}
