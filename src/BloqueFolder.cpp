#include "BloqueFolder.h"

BloqueFolder::BloqueFolder()::Bloque(nombre,numB,a,tamanoB)
{
    nombre = nombre;
    numBloque = numB;
    archivo = a;
    tamanoBloque = tamanoB;
}

list<FileEntry*> * BloqueFolder::getEntriesList()
{
    return entriesList;
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

Archivo * BloqueFolder::getArchivo()
{
    return Bloque::getArchivo();
}


