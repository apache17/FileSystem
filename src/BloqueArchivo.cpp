#include "BloqueArchivo.h"

BloqueArchivo::BloqueArchivo(char * nombre, int numB, Archivo * a, int tamanoB)
{
    nombre = nombre;
    numBloque = numB;
    archivo = a;
    tamanoBloque = tamanoB;
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
    return nombre;
}

int BloqueArchivo::getNumBloque()
{
    return numBloque;
}

int BloqueArchivo::getTamanoBloque()
{
    return tamanoBloque;
}

Archivo * BloqueArchivo::getArchivo()
{
    return archivo;
}
