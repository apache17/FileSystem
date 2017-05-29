#include "BloqueFolder.h"

BloqueFolder::BloqueFolder(char * nombre, int numB, Archivo * a,int tamanoB,bool disp):Bloque(nombre,numB,tamanoB,disp)
{
    espacioUtilizado = 0;
    archivo = a;
}

Archivo * BloqueFolder::getArchivo()
{
    return archivo;
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

void BloqueFolder::agregarFileEntry(char* n, int fB, int lB, bool isF, int s,int pI,int pF)
{
    FileEntry * fe;
    fe->setFirstBlock(fB);
    fe->setIsFolder(isF);
    fe->setLastBlock(lB);
    fe->setNombre(n);
    fe->setSize(s);
    fe->setPosInicio(pI);
    fe->setPosFinal(pF);

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
bool BloqueFolder::getDisponible()
{
    return Bloque::getDisponible();
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


