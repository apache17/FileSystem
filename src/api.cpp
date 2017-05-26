#include "api.h"

API::API(){

}

Bloque * API::get(list<Bloque*> lista, int _i){
    list<Bloque*>::iterator it = lista.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}


Bloque * API::addBloque(Archivo *arch, string tipo)
{
    if(tipo == "Archivo")
    {
        int pos = mb->getSigDisponible();
        list<Bloque*> lista = disco->getListaBloques();
        Bloque * ba = get(lista,pos-1);

        ba = new BloqueArchivo(arch->nombre,pos,arch,arch->getSize(),1);
        mb->setSiguienteDisponible(pos+1);
        return ba;
    }

    else if(tipo == "Carpeta")
    {
        int pos = mb->getSigDisponible();
        list<Bloque*> lista = disco->getListaBloques();
        Bloque * bf = get(lista,pos-1);

        bf = new BloqueFolder(arch->nombre,pos,arch,arch->getSize(),1);
        mb->setSiguienteDisponible(pos+1);
        return bf;
    }
    return NULL;

}
