#include "BloqueFolder.h"

BloqueFolder::BloqueFolder(char * nombre, int numB, Archivo * a,int tamanoB,bool disp):Bloque(nombre,numB,tamanoB,disp)
{

}

bool BloqueFolder::getDisponible()
{
    return Bloque::getDisponible();
}

vector<FileEntry*> * BloqueFolder::getListaEntries()
{
    return listaEntries;
}

void BloqueFolder::agregarEntry(FileEntry* fe)
{
    listaEntries->push_back(fe);
}

void BloqueFolder::cargar()
{

}

void BloqueFolder::initFromChar(char * d)
{
    int pos = 0;
    memcpy(&nombre, &d[pos], 30);
    pos+=30;
    memcpy(&numBloque, &d[pos], 4);
    pos+=4;
    memcpy(&tamanoBloque, &d[pos], 4);
    pos+=4;
}


char * BloqueFolder::getNombre()
{
    return Bloque::getNombre();
}

int BloqueFolder::getNumBloque()
{
    return Bloque::getNumBloque();
}

int BloqueFolder::getTamanoBloque()
{
    return Bloque::getTamanoBloque();
}


