#include "BloqueFolder.h"

BloqueFolder::BloqueFolder(char * nombre, int numB):Bloque(nombre,numB)
{
    espacioUtilizado = 0;
}

void BloqueFolder::setNombre(char * n)
{
    nombre = n;
}

int BloqueFolder::getEspacioUtilizado()
{
    return espacioUtilizado;
}

void BloqueFolder::setEspacioUtilizado(int eU)
{
    espacioUtilizado += eU;
}

void BloqueFolder::agregarFileEntry(FileEntry * fe,char* n, int fB, int lB, bool isF, int s)
{
    fe->setFirstBlock(fB);
    fe->setIsFolder(isF);
    fe->setLastBlock(lB);
    fe->setNombre(n);
    fe->setSize(s);
    listaEntries.push_back(fe);
}

void BloqueFolder::imprimirN()
{
    if(strlen(nombre)!=0)
    {
        for(int x = 0; x<strlen(nombre);x++)
            cout<<nombre[x];
        cout<<""<<endl;
    }
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


