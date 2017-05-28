#include "DiscoVirtual.h"

DiscoVirtual::DiscoVirtual(Archivo * arch,int tamArc,int tamBlo){
    archivo = arch;
    tamArchivo = tamArc;
    tamBloque = tamBlo;
}

void DiscoVirtual::formatear(char *nombreArchivo)
{
    Archivo * a = new Archivo(nombreArchivo);
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
    mb = new MasterBlock(this->archivo,tamBloque,(tamArchivo/tamBloque),0,1);
    this->mb->cargar();
}

/*vector<FileEntry*> DiscoVirtual::listarArchivosEnRaiz()
{
    if(mb->getSigDisponible() == 1)
        return new vector<FileEntry*>;

    int numeroDeBloque = mb->getPrimerBloque();

    BloqueFolder * bf = new BloqueFolder("root",numeroDeBloque,this->archivo,mb->getTamanoBloque(),0);
    bf->cargar();

    return bf->getListaEntries();
}
*/
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

vector<Bloque*> DiscoVirtual::getListaBloques()
{
    return listaBloques;
}

void DiscoVirtual::guardar()
{
    char * data = new char[8];

    int pos = 0;
    memcpy(&data[pos], &tamArchivo, 4);
    pos+=4;
    memcpy(&data[pos], &tamBloque, 4);
    pos+=4;
    archivo->escribir(data);
}
