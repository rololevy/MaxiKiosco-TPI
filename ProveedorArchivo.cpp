#include <iostream>
using namespace std;
#include "ProveedorArchivo.h"


ProveedorArchivo::ProveedorArchivo(){
_nombreArchivo="Proveedores.dat";
}


 Proveedores ProveedorArchivo::leerUno(int pos){
 FILE *ProvArchivo = fopen(_nombreArchivo.c_str(), "rb");
 if(ProvArchivo==NULL){
    cout << "FALLA en el ingreso al archivo" << endl;
 }
 Proveedores maxi;
 fseek(ProvArchivo,sizeof(Proveedores)*pos,SEEK_SET);
 fread(&maxi,sizeof(Proveedores),1,ProvArchivo);
 fclose(ProvArchivo);
 return maxi;
 }


 bool ProveedorArchivo::Guardar (Proveedores PROV, int Maxi){
 bool guardado;
 FILE *Provfile;

 Provfile = fopen (_nombreArchivo.c_str(), "rb+");

 if (Provfile== nullptr){
    return false;
 }

 fseek (Provfile, sizeof(Proveedores)*Maxi, SEEK_SET);
 guardado =fwrite(&PROV, sizeof(Proveedores), 1, Provfile);

 fclose(Provfile);

 return guardado;
 }




bool ProveedorArchivo::Modificar(Proveedores maxi, int pos){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(),"rb+");
if(ProvArchivo==NULL){
    return false;
}
fseek(ProvArchivo,sizeof(Proveedores)* pos,SEEK_SET);
bool Modif = fwrite(&maxi,sizeof(Proveedores),1,ProvArchivo);
fclose(ProvArchivo);
return Modif;
    }

/*  ------> para eliminar
bool ProveedorArchivo::Eliminar(Proveedores maxi,int pos){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(), "rb+");
if(ProvArchivo==NULL){
    cout << "no se pudo abrir el archivo para su eliminacion" << endl;
return false;
}
ProveedorArchivo ProveedorAeliminar;
fseek(ProvArchivo, sizeof(Proveedores) * pos, SEEK_SET);
fread(&ProveedorAeliminar, sizeof(Proveedores), 1, ProvArchivo);
ProveedorAeliminar.setregActivo(false);
fseek(ProvArchivo, sizeof(Proveedores) * pos, SEEK_SET);
bool eliminacionExitosa = fwrite(&ProveedorAeliminar, sizeof(Proveedores), 1, ProvArchivo) == 1;
fclose(ProvArchivo);
    return eliminacionExitosa;
}*/

void ProveedorArchivo::setregActivo(bool estado){
_registroActivo=estado;
}
bool ProveedorArchivo::getregActivo(){
return _registroActivo;
}


int ProveedorArchivo::listarTodos() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    int TotalActivos=0;
    if (archivo == nullptr) return 0;
    Proveedores maxi;
    while (fread(&maxi, sizeof(Proveedores), 1, archivo)) {
        if (maxi.getEstado()) {
           cout << "======================================" << endl;
            maxi.Mostrar();
            TotalActivos++;
        }
    }
    fclose(archivo);
    return TotalActivos;
}



int ProveedorArchivo::getCantidadRegistros(){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(),"rb");
if(ProvArchivo==NULL){
    return 0;
}
fseek(ProvArchivo,0,SEEK_END);
int cantRegistros= ftell(ProvArchivo) / sizeof(Proveedores);
fclose(ProvArchivo);
return cantRegistros;
}


int ProveedorArchivo::buscarProveedor(std::string IDproveedor){
 FILE *ProvArchivo;
 Proveedores Prov;
 ProvArchivo= fopen (_nombreArchivo.c_str() , "rb");
 if (ProvArchivo==nullptr){

    return -1;
 }
 int pos=0;
 while (fread (&Prov,sizeof (Proveedores), 1, ProvArchivo)==1){

    if (Prov.getidProveedor()==IDproveedor){
        fclose (ProvArchivo);
        return pos;

    }

    pos++;
 }
 fclose (ProvArchivo);
 return -1;


 }

 bool ProveedorArchivo::leerMuchos(Proveedores reg[], int cantidad){
 FILE *pFile;

 pFile= fopen (_nombreArchivo.c_str(), "rb");

 if (pFile == nullptr){

    return reg;
 }

fread(reg, sizeof(Proveedores), cantidad, pFile);
fclose(pFile);
 return true;
}
