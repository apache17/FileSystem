#include "DiscoVirtual.h"

DiscoVirtual::DiscoVirtual(Archivo * arch, int tamArchivo, int tamBloque){
    archivo = arch;
    tamArchivo = 1000;
    tamBloque = 100;
}

DiscoVirtual * DiscoVirtual::crearDiscoVirtual(char *nombreArchivo){
    archivo = new Archivo(nombreArchivo,"C:/",0,tamBloque);
    archivo->abrir();
    DiscoVirtual * disc = new DiscoVirtual(archivo,tamArchivo,tamBloque);
    disc->formatear();
    return disc;
}

void DiscoVirtual::formatear(){
    mb = new MasterBlock(archivo,tamBloque,(tamArchivo/tamBloque),-1,1);
    mb->guardar();

    for(int a = 0; a<mb->getCantBloques(); a++)
    {
        Bloque * bloque = asignarSiguienteBloque(a);

    }
    mb->setSiguienteDisponible(1);
    mb->guardar();
}

Bloque * DiscoVirtual::asignarSiguienteBloque(int numeroBloque)
{
    string str = "Bloque";
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    Bloque * bloque = new Bloque(cstr,numeroBloque,mb->getTamanoBloque(),true);
    listaBloques.push_back(bloque);
    return bloque;
}

void DiscoVirtual::cargar(){
    archivo->abrir();
    mb = new MasterBlock(this->archivo,tamBloque,(tamArchivo/tamBloque),-1,1);
    this->mb->cargar();
}

list<Archivo*> * DiscoVirtual::listarArchivosEnRaiz()
{
    if(mb->getSigDisponible() == 1)
        return new list<Archivo*>;

    int numeroDeBloque = mb->getPrimerBloque();

    BloqueFolder * bf = new BloqueFolder("root",numeroDeBloque,this->archivo,mb->getTamanoBloque(),0);
    bf->cargar();

    return bf->getListaArchivo();
}

int DiscoVirtual::getTamanoArchivo()
{
    return tamArchivo;
}

int DiscoVirtual::getTamanoBloque()
{
    return tamBloque;
}

Archivo * DiscoVirtual::getArchivo()
{
    return archivo;
}

MasterBlock * DiscoVirtual::getMasterBlock()
{
    return mb;
}

list<Bloque*> DiscoVirtual::getListaBloques()
{
    return listaBloques;
}
