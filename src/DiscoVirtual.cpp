#include "DiscoVirtual.h"

DiscoVirtual::DiscoVirtual(Archivo * arch, const int tamArchivo, const int tamBloque){

}

DiscoVirtual * DiscoVirtual::crearDiscoVirtual(char *nombreArchivo)
{
    archivo = new Archivo(nombreArchivo,2);
    archivo->abrir();
    DiscoVirtual * disc = new DiscoVirtual(archivo,tamArchivo,tamBloque);
    disc->formatear();
    return disc;
}

void DiscoVirtual::formatear()
{

}


void DiscoVirtual::cargar()
{
    archivo->abrir();
    mb = new MasterBlock(this->archivo,tamBloque);
    this->mb->cargar();
}

BloqueFolder * DiscoVirtual::listarArchivosEnRaiz()
{

    if(mb->sigDisponible == 1)
        return lista;

    int numeroDeBloque = mb->primero;

    BloqueFolder * bf = new BloqueFolder("root",numeroDeBloque,this->archivo);
    bf->cargar(); /*mismo que el cargar de aqui*/

    return bf->entriesList;
}
