#include <iostream>
#include "ProveedorArchivo.h"
using namespace std;


ProveedorArchivo::ProveedorArchivo(std::string nombreArchivo){
_nombreArchivo=nombreArchivo;
}



 ProveedorArchivo ProveedorArchivo::leerUno(int pos){
 FILE *ProvArchivo = fopen(_nombreArchivo.c_str(), "rb");
 if(ProvArchivo==NULL){
    cout << "FALLA en el ingreso al archivo" << endl;
 }
 ProveedorArchivo maxi;
 fseek(ProvArchivo,sizeof(ProveedorArchivo)*pos,SEEK_SET);
 fread(&maxi,sizeof(ProveedorArchivo),1,ProvArchivo);
 fclose(ProvArchivo);
 return maxi;
 }


bool ProveedorArchivo::Guardar(Proveedores maxi){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(),"ab");
if(ProvArchivo==NULL){
        return false;
    }
bool Archi= fwrite(&maxi,sizeof(ProveedorArchivo),1, ProvArchivo);
fclose(ProvArchivo);
return Archi;
    }


bool ProveedorArchivo::Modificar(Proveedores maxi, int pos){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(),"rb+");
if(ProvArchivo==NULL){
    return false;
}
fseek(ProvArchivo,sizeof(ProveedorArchivo)* pos,SEEK_SET);
bool Modif = fwrite(&maxi,sizeof(ProveedorArchivo),1,ProvArchivo);
fclose(ProvArchivo);
return Modif;
    }


bool ProveedorArchivo::Eliminar(Proveedores maxi,int pos){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(), "rb+");
if(ProvArchivo==NULL){
    cout << "no se pudo abrir el archivo para su eliminacion" << endl;
return false;
}
ProveedorArchivo ProveedorAeliminar;
fseek(ProvArchivo, sizeof(ProveedorArchivo) * pos, SEEK_SET);
fread(&ProveedorAeliminar, sizeof(ProveedorArchivo), 1, ProvArchivo);
ProveedorAeliminar.setregActivo(false);
fseek(ProvArchivo, sizeof(ProveedorArchivo) * pos, SEEK_SET);
bool eliminacionExitosa = fwrite(ProveedorAeliminar, sizeof(ProveedorArchivo), 1, ProvArchivo) == 1;
fclose(ProvArchivo);
    return eliminacionExitosa;
}

void ProveedorArchivo::setregActivo(bool estado){
_registroActivo=estado;
}
bool ProveedorArchivo::getregActivo()const{
return _registroActivo;
}


void ProveedorArchivo::listarTodos(int cantRegistros, ProveedorArchivo *vector){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(), "rb");
if(ProvArchivo==NULL){
    return;
}
for(int i=0;i<cantRegistros;){

   if(vector.getregActivo()){
    fread(&vector[i],siziof(ProveedorArchivo),1,ProvArchivo);

   }
}
fclose(ProvArchivo);

}

int ProveedorArchivo::getCantidadRegistros(){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(),"rb");
if(ProvArchivo==NULL){
    return 0;
}
fseek(ProvArchivo,0,SEEK_END);
int cantRegistros= ftell(ProvArchivo) / sizeof(ProveedorArchivo);
fclose(ProvArchivo);
return cantRegistros;
}
