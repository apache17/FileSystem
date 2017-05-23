#include "BloqueFolder.h"

BloqueFolder::BloqueFolder(string dir, int numB, Archivo * a, int tamanoB)
{
    direccion = dir;
    numBloque = numB;
    archivo = a;
    tamanoBloque = tamanoB;
}

void BloqueFolder::cargar()
{
    this->archivo->abrir();
    char * data = archivo->leer(0, tamanoBloque);
    initFromChar(data);
}

void BloqueFolder::initFromChar(char * d)
{
    int pos = 0;

    memcpy(&direccion, &d[pos], 30);
    pos+=30;
    memcpy(&numBloque, &d[pos], 4);
    pos+=4;
    memcpy(&tamanoBloque, &d[pos], 4);
    pos+=4;

}
