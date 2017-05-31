#include "DiscoVirtual.h"

DiscoVirtual::DiscoVirtual(Archivo * arch,int tamArc,int tamBlo){
    archivo = arch;
    tamArchivo = tamArc;
    tamBloque = tamBlo;
}

void DiscoVirtual::formatear()
{

    mb = new MasterBlock(tamBloque,(tamArchivo/tamBloque),-1,1);
    mb->guardar();

    for(int a = 0; a<mb->getCantBloques(); a++)
        asignarSiguienteBloque(a);

    mb->setSiguienteDisponible(1);
    char * mB = mb->masterBlockToChar();
    archivo->escribir(mB,1,strlen(mB));

}

Bloque * DiscoVirtual::asignarSiguienteBloque(int numeroBloque)
{
    string str = "Bloque";
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    Bloque * bloque = new Bloque(cstr,numeroBloque);
    listaBloques.push_back(bloque);
    return bloque;
}

void DiscoVirtual::cargar(){
    archivo->abrir();
    mb = new MasterBlock(tamBloque,(tamArchivo/tamBloque),0,1);
    this->mb->cargar();
}

BloqueFolder * DiscoVirtual::getRaiz()
{
    return raiz;
}

void DiscoVirtual::setRaiz(BloqueFolder * bf)
{
    raiz = bf;
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

vector<Bloque*> DiscoVirtual::getListaBloques()
{
    return listaBloques;
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
