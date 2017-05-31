#include "FileEntry.h"

FileEntry::FileEntry() {
    nombre = {"a"};
    firstBlock = 0;
    lastBlock = 0;
    isFolder = false;
    size = 0;
}
void FileEntry::imprimirEntry()
{
    cout<<"Nombre : ";
    imprimirNombre();
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

