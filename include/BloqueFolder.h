#ifndef BLOQUEFOLDER_H
#define BLOQUEFOLDER_H

#include <stdio.h>
#include <iostream>
#include <list>
#include <string.h>
#include "FileEntry.h"
#include "bloque.h"

class BloqueFolder:public Bloque{
public:
    BloqueFolder(char * nombre, int numB, Archivo * a,int tamanoB);

    int getTamanoBloque();
    int getNumBloque();
    char * getNombre();
    Archivo * getArchivo();
    list<FileEntry*> * getEntriesList();

    void agregarEntry(FileEntry * fe);
    void cargar();

private:
    void initFromChar(char * d);

    list<FileEntry*> * entriesList;
    int tamanoBloque;
    int numBloque;
    char * nombre;
    Archivo * archivo;
};

#endif // BLOQUEFOLDER_H
