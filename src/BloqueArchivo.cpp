#include "BloqueArchivo.h"

BloqueArchivo::BloqueArchivo(char * nombre, int numB,bool escritura):Bloque(nombre,numB)
{
    escritura = escritura;
    fe = new FileEntry();
}

bool BloqueArchivo::getEscritura()
{
    return escritura;
}

void BloqueArchivo::setEscritura(bool escritura)
{
    escritura = escritura;
}

void BloqueArchivo::setFileEntry(char* n, int fB, int lB, bool isF, int s)
{
    fe->setFirstBlock(fB);
    fe->setIsFolder(isF);
    fe->setLastBlock(lB);
    fe->setNombre(n);
    fe->setSize(s);
}

void BloqueArchivo::imprimirContenido()
{
    /*char * data = archivo->leer(1,archivo->getSize());
    for(int x = 0; x<strlen(data);x++)
        cout<<data[x];
    cout<<""<<endl;*/
}

FileEntry * BloqueArchivo::getFileEntry()
{
    return fe;
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

