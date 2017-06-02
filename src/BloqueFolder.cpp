#include "BloqueFolder.h"

BloqueFolder::BloqueFolder(char * nombre, int numB,int tamB,Archivo * archivo):Bloque(nombre,numB,tamB)
{
    siguiente = NULL;
    anterior = NULL;
    archivo = archivo;
    fe = new FileEntry();
}

void BloqueFolder::setFileEntry(char* n, int fB, int lB, bool isF, int s)
{
    fe->setFirstBlock(fB);
    fe->setIsFolder(isF);
    fe->setLastBlock(lB);
    fe->setNombre(n);
    fe->setSize(s);
}

void BloqueFolder::setNombre(char * n)
{
    nombre = n;
}


Archivo * BloqueFolder::getArchivo()
{
    return archivo;
}

FileEntry * BloqueFolder::getFileEntry()
{
    return fe;
}

BloqueFolder * BloqueFolder::getSiguiente()
{
    return siguiente;
}

BloqueFolder * BloqueFolder::getAnterior()
{
    return anterior;
}

void BloqueFolder::setSiguiente(BloqueFolder * bf)
{
    siguiente = bf;
}

void BloqueFolder::setAnterior(BloqueFolder * bf)
{
    anterior = bf;
}

void BloqueFolder::setTamanoBloque(int tB)
{
    tamanoBloque += tB;
    fe->setSize(tamanoBloque);
}

void BloqueFolder::agregarFileEntry(FileEntry * fe)
{
    listaEntries.push_back(fe);
}


vector<FileEntry*> BloqueFolder::getListaEntries()
{
    return listaEntries;
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


void BloqueFolder::imprimirNombre()
{
    char * n = nombre;
    for(int x = 0;x<strlen(n);x++)
        cout<<n[x];
    cout<<strlen(n);
    cout<<""<<endl;

}

