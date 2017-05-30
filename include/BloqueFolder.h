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
    BloqueFolder(char * nombre, int numB,int tamanoB);

    int getTamanoBloque();
    void imprimirN();
    int getNumBloque();
    int getEspacioUtilizado();
    void setEspacioUtilizado(int eU);
    char * getNombre();
    void setNombre(char * n);
    vector<FileEntry*> getListaEntries();
    void cargar();
    void agregarFileEntry(FileEntry * fe,char* n, int fB, int lB, bool isF, int s,int pI,int pF);
    void printRoot();



private:
    void initFromChar(char * d);

    vector<FileEntry*> listaEntries;
    int tamanoBloque;
    int numBloque;
    int espacioUtilizado;
    char * nombre;
};

#endif // BLOQUEFOLDER_H
