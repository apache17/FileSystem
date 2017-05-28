#include "FileEntry.h"

FileEntry::FileEntry(char *nombre, int firstBlock, int lastBlock, bool isFolder, int size) {
    this->nombre = nombre;
    this->firstBlock = firstBlock;
    this->lastBlock = lastBlock;
    this->isFolder = isFolder;
    this->size = size;
}
void FileEntry::imprimirEntry()
{
    imprimirNombre();
    cout<<getFirstBLock()<<endl;
    cout<<getLastBlock()<<endl;
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
    cout<<"Es un Archivo"<<endl;
}

int FileEntry::getSize()
{
    return size;
}
