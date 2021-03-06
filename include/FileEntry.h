#ifndef FILEENTRY_H
#define FILEENTRY_H
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

class FileEntry
{
    public:
        FileEntry();

        char * getNombre();
        int getFirstBLock();
        int getLastBlock();
        bool getEsFolder();
        int getSize();

        void setFirstBlock(int fB);
        void setLastBlock(int lB);
        void setNombre(char * n);
        void setSize(int s);
        void setIsFolder(bool iF);

        void imprimirEntry();

    private:
        char* nombre;
        int firstBlock;
        int lastBlock;
        bool isFolder;
        int size;
};

#endif // FILEENTRY_H
