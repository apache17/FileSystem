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
    cout<<"Direccion: ";
    char * nombre = getNombre();
    for(int x = 0; x < strlen(nombre);x++)
        cout<<nombre[x];
    cout<<""<<endl;

    cout<<"First Block: ";
    cout<<getFirstBLock()<<endl;
    cout<<"Last Block: ";
    cout<<getLastBlock()<<endl;

    if(getEsFolder())
        cout<<"Tipo: Folder"<<endl;
    else
        cout<<"Tipo: Archivo"<<endl;
    cout<<"Size: ";
    cout<<getSize()<<endl;

}

 char * FileEntry::getNombre()
 {
     return nombre;
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
    size += s;
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

bool FileEntry::getEsFolder()
{
    return isFolder;
}

int FileEntry::getSize()
{
    return size;
}

