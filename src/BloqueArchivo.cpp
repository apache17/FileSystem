#include "BloqueArchivo.h"

BloqueArchivo::BloqueArchivo(char * nombre, int numB, Archivo * a,int tamanoB, bool disp):Bloque(nombre,numB,tamanoB,disp)
{
    archivo = a;
}

void BloqueArchivo::setFileEntry(char* n, int fB, int lB, int isF, int s)
{
    fe = new FileEntry(n,fB,lB,isF,s);
}

FileEntry * BloqueArchivo::getFileEntry()
{
    return fe;
}

bool BloqueArchivo::getDisponible()
{
    return Bloque::getDisponible();
}

void BloqueArchivo::initFromChar(char * d)
{
    int pos = 0;
    memcpy(&nombre, &d[pos], 30);
    pos+=30;
    memcpy(&numBloque, &d[pos], 4);
    pos+=4;
    memcpy(&tamanoBloque, &d[pos], 4);
    pos+=4;
}

char * BloqueArchivo::getNombre()
{
    return Bloque::getNombre();
}

int BloqueArchivo::getNumBloque()
{
    return Bloque::getNumBloque();
}

int BloqueArchivo::getTamanoBloque()
{
    return Bloque::getTamanoBloque();
}

Archivo * BloqueArchivo::getArchivo()
{
    return archivo;
}
