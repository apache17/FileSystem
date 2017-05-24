#include "BloqueArchivo.h"

BloqueArchivo::BloqueArchivo(char * nombre, int numB, Archivo * a,int tamanoB):Bloque(nombre,numB,a,tamanoB)
{

}

void BloqueArchivo::guardar()
{

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
    return Bloque::getArchivo();
}
