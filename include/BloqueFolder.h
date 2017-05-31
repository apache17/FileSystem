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
    BloqueFolder(char * nombre, int numB);

    int getTamanoBloque();
    void imprimirN();
    int getNumBloque();
    int getEspacioUtilizado();
    void setEspacioUtilizado(int eU);
    char * getNombre();
    void setNombre(char * n);
    vector<FileEntry*> getListaEntries();
    void cargar();
    void agregarFileEntry(FileEntry * fe);
    void printRoot();

    BloqueFolder * getSiguiente();
    BloqueFolder * getAnterior();
    void setSiguiente(BloqueFolder * bf);
    void setAnterior(BloqueFolder * bf);



private:
    void initFromChar(char * d);

    vector<FileEntry*> listaEntries;
    int tamanoBloque;
    int numBloque;
    int espacioUtilizado;
    char * nombre;
    BloqueFolder * siguiente;
    BloqueFolder * anterior;

};

#endif // BLOQUEFOLDER_H
