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
    void imprimirN();
    int getNumBloque();
    int getEspacioUtilizado();
    void setEspacioUtilizado(int eU);
    char * getNombre();
    void setNombre(char * n);
    Archivo * getArchivo();
    vector<FileEntry*> getListaEntries();
    bool getDisponible();
    void cargar();
    void agregarFileEntry(char* n, int fB, int lB, bool isF, int s,int pI,int pF);


private:
    void initFromChar(char * d);

    vector<FileEntry*> listaEntries;
    int tamanoBloque;
    int numBloque;
    int espacioUtilizado;
    bool disponible;
    char * nombre;
    Archivo * archivo;

};

#endif // BLOQUEFOLDER_H
