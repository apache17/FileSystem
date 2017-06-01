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
    BloqueFolder(char * nombre, int numB, int tamB,Archivo * archivo);

    int getTamanoBloque();
    void setTamanoBloque(int tB);

    int getNumBloque();
    char * getNombre();

    FileEntry * getFileEntry();
    void setFileEntry(char* n, int fB, int lB, bool isF, int s);
    vector<FileEntry*> getListaEntries();
    void agregarFileEntry(FileEntry * fe);
    void escribirEntries(int pos);
    void imprimirNombre();
    void cargar();
    void setNombre(char * n);

    BloqueFolder * getSiguiente();
    BloqueFolder * getAnterior();
    void setSiguiente(BloqueFolder * bf);
    void setAnterior(BloqueFolder * bf);
    Archivo * getArchivo();


private:
    void initFromChar(char * d);
    Archivo * archivo;
    vector<FileEntry*> listaEntries;
    int tamanoBloque;
    int numBloque;
    char * nombre;
    BloqueFolder * siguiente;
    BloqueFolder * anterior;
    FileEntry *fe;

};

#endif // BLOQUEFOLDER_H
