#ifndef BLOQUEFOLDER_H
#define BLOQUEFOLDER_H
#include <vector>
#include <stdio.h>
#include <iostream>
#include <list>
#include <string.h>
#include "FileEntry.h"
#include "bloque.h"

class BloqueFolder:public Bloque{
public:
    BloqueFolder(char * nombre, int numB, Archivo * a,int tamanoB,bool disp);

    int getTamanoBloque();
    int getNumBloque();
    char * getNombre();
    vector<FileEntry*> * getListaEntries();
    bool getDisponible();
    void agregarEntry(FileEntry * fe);
    void cargar();
    void setFileEntry(char* nombre, int firstBlock, int lastBlock, int isFolder, long size);

private:
    void initFromChar(char * d);

    vector<FileEntry*> * listaEntries;
    int tamanoBloque;
    int numBloque;
    bool disponible;
    char * nombre;

};

#endif // BLOQUEFOLDER_H
