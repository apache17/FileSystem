#include "FileEntry.h"

FileEntry::FileEntry() {
    nombre = {"a"};
    firstBlock = 0;
    lastBlock = 0;
    isFolder = false;
    size = 0;
    posFinal = 0;
    posInicio = 0;
}
void FileEntry::imprimirEntry()
{
    imprimirNombre();
    cout<<"Posicion de Inicio : ";
    cout<<getPosInicio()<<endl;
    cout<<"Posicion Final : ";
    cout<<getPosFinal()<<endl;
    cout<<"Primer Bloque : ";
    cout<<getFirstBLock()<<endl;
    cout<<"Ultimo Bloque : ";
    cout<<getLastBlock()<<endl;
    cout<<"Tamano : ";
    cout<<getSize()<<endl;
    esFolder();
}

 void FileEntry::imprimirNombre()
 {
     for(int x = 0; x < strlen(nombre);x++)
        cout<<nombre[x];
     cout<<""<<endl;
 }

 void FileEntry::setFirstBlock(int fB)
 {
     firstBlock = fB;
 }

void FileEntry::setPosInicio(int pI)
{
     posInicio = pI;
}

void FileEntry::setPosFinal(int pF)
{
     posFinal = pF;
}

int FileEntry::getPosFinal()
{
    return posFinal;
}

int FileEntry::getPosInicio()
{
    return posInicio;
}

void FileEntry::setLastBlock(int lB)
{
    lastBlock = lB;
}

void FileEntry::setNombre(char * n)
{
    nombre = n;
}

void FileEntry::setSize(int s)
{
    size = s;
}

void FileEntry::setIsFolder(bool iF)
{
    isFolder = iF;
}

int FileEntry::getFirstBLock()
{
    return firstBlock;
}

int FileEntry::getLastBlock()
{
    return lastBlock;
}

void FileEntry::esFolder()
{
    if(isFolder)
        cout<<"Es un Folder"<<endl;
    else
        cout<<"Es un Archivo"<<endl;
}

int FileEntry::getSize()
{
    return size;
}

