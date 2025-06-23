#include <iostream>
using namespace std;
#include "Productos.h"
#include "ProductosArchivo.h"

ProductosArchivo::ProductosArchivo(){
 _nombreArchivo="ProductosArchivo.dat";
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

int ProductosArchivo::buscarProducto(std::string IDProducto){
 FILE *pFile;
 Productos prod;
 int pos=0;
 pFile= fopen (_nombreArchivo.c_str() , "rb");
 if (pFile==nullptr){

    cout<<"No se pudo abrir el archivo";
    return -1;
 }
 int i=0;
 while (fread (&prod,sizeof (Productos), 1, pFile)){

    if (prod.getIDProducto()==IDProducto){
        fclose (pFile);
        return i;

    }
    i++;
 }
 fclose (pFile);
 return -1;


 }

 /*bool ProductosArchivo::Modificar (Productos mod, int pos){
 Productos mode;

 FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");

 if(pFile==NULL){
        cout<<"No se pudo abrir el archivo";
    return false;
 }
 fseek(pFile,sizeof(ProductosArchivo)* pos,SEEK_SET);///seek_set en clases estaba el 0
 bool Modif = fwrite(&mod,sizeof(ProductosArchivo),1,pFile);
 fclose(pFile);
 return Modif;


 }*/

/* bool ProductosArchivo::Eliminar(std::string IDProducto){
    Productos reg;
    ProductosArchivo archi;
    int pos=archi.buscarProducto(IDProducto);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leer(pos);
    ///en reg tengo el registro a borrar
    reg.setEstado(false);

    return archi.Modificar (reg, pos);
}*/

int ProductosArchivo::listarTodos() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    int TotalActivos=0;
    if (archivo == nullptr) return 0;
    Productos maxi;
    while (fread(&maxi, sizeof(Productos), 1, archivo)) {
        if (maxi.getEstado()) {
           cout << "======================================" << endl;
            maxi.mostrar();
            TotalActivos++;
        }
    }
    fclose(archivo);
    return TotalActivos;
}




