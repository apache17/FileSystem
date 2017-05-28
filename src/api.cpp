#include "api.h"

API::API(){

}

Bloque * API::get(vector<Bloque*> lista, int i){
    return lista[i];
}


Bloque * API::addBloque(Archivo *arch, string tipo, DiscoVirtual * dv)
{
    char * hola = {"Boris"};
    if(tipo == "Archivo")
    {
        int pos = dv->getMasterBlock()->getSigDisponible();
        vector<Bloque*> lista = dv->getListaBloques();
        Bloque * b = lista[pos];
        int size = arch->getSize()/4096;

        if(size<=1){
            b = new BloqueArchivo(arch->direccion,pos,arch,arch->getSize(),false);
            dv->getMasterBlock()->setSiguienteDisponible(pos+1);
            BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
            ba->setFileEntry(arch->direccion,pos,arch->getSize(),false,arch->getSize());
            dv->listaBloqueArchivo.push_back(ba);
            return ba;
        }
        else if(size>1)
        {
            if(arch->getSize()%4096>0)
                size++;
            b = new BloqueArchivo(arch->direccion,pos,arch,arch->getSize(),1);
            BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
            dv->getMasterBlock()->setSiguienteDisponible(pos+size);
            ba->setFileEntry(arch->direccion,pos,arch->getSize(),false,arch->getSize());
            return ba;
        }
    }
    return NULL;

}

void API::dir(DiscoVirtual * dv)
{

}
