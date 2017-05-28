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

        void imprimirNombre();
        int getPosInicio();
        int getPosFinal();
        int getFirstBLock();
        int getLastBlock();
        void esFolder();
        int getSize();

        void setPosInicio(int pI);
        void setPosFinal(int pF);
        void setFirstBlock(int fB);
        void setLastBlock(int lB);
        void setNombre(char * n);
        void setSize(int s);
        void setIsFolder(bool iF);

        void imprimirEntry();

    private:
        char* nombre;
        int posInicio;
        int posFinal;
        int firstBlock;
        int lastBlock;
        bool isFolder;
        int size;
};

#endif // FILEENTRY_H
