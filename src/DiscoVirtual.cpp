#include "DiscoVirtual.h"

DiscoVirtual::DiscoVirtual(Archivo * arch, int tamArchivo, int tamBloque){
    archivo = arch;
    tamArchivo = 1000;
    tamBloque = 100;
}

DiscoVirtual * DiscoVirtual::crearDiscoVirtual(char *nombreArchivo){
    archivo = new Archivo(nombreArchivo,0,1000);
    archivo->abrir();
    DiscoVirtual * disc = new DiscoVirtual(archivo,tamArchivo,tamBloque);
    disc->formatear();
    return disc;
}

void DiscoVirtual::formatear(){
    MasterBlock * masterb = new MasterBlock(archivo,tamBloque,(tamArchivo/tamBloque),-1,1);
    masterb->guardar();
    this->mb = masterb;
    for(int a = 0; a<mb->cantBloques; a++){
        BloqueArchivo * bA = bA->asignarSiguienteBloque();
        bA->guardar();
    }
    mb->sigDisponible = 1;
    mb->guardar();
}


void DiscoVirtual::cargar(){
    archivo->abrir();
    mb = new MasterBlock(this->archivo,tamBloque,(tamArchivo/tamBloque),-1,1);
    this->mb->cargar();
}

list<Archivo*> * DiscoVirtual::listarArchivosEnRaiz()
{
    if(mb->sigDisponible == 1)
        return new list<Archivo*>;

    int numeroDeBloque = mb->primero;

    BloqueFolder * bf = new BloqueFolder("root",numeroDeBloque,this->archivo,mb->tamanoBloque);
    bf->cargar(); /*mismo que el cargar de aqui*/

    return &bf->entriesList;
    /*ADD A NUEVO BF O PRINT??*/
}
