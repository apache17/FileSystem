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


Bloque * API::addBloque(Archivo *arch, string tipo, DiscoVirtual * dv)
{
    if(tipo == "Archivo")
    {
        int pos = dv->getMasterBlock()->getSigDisponible();
        list<Bloque*> lista = dv->getListaBloques();
        Bloque * b = get(lista,pos-1);
        int size = arch->getSize()/4096;

        if(size<=1){
            b = new BloqueArchivo(arch->direccion,pos,arch,arch->getSize(),false);
            dv->getMasterBlock()->setSiguienteDisponible(pos+1);
            BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
            ba->setFileEntry(arch->direccion,pos,size,false,arch->getSize());
            return ba;
        }
        else if(size>1)
        {
            if(arch->getSize()%4096>0)
                size++;
            b = new BloqueArchivo(arch->direccion,pos,arch,arch->getSize(),1);
            BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
            dv->getMasterBlock()->setSiguienteDisponible(pos+size);
            //ba->setFileEntry(arch->nombre,pos,size,false,arch->getSize());
            return ba;
        }
    }
    return NULL;

}
