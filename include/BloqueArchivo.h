#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include <stdio.h>
#include "bloque.h"
#include "FileEntry.h"
using namespace std;

class BloqueArchivo:public Bloque
{
    public:
        BloqueArchivo(char * nombre, int numB,int tamanoB);
        int getTamanoBloque();
        int getNumBloque();
        char * getNombre();
        FileEntry * getFileEntry();
        void setFileEntry(char* n, int fB, int lB, bool isF, int s,int pI,int pF);
        void imprimirContenido();

    private:
        void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        FileEntry *fe;
};

#endif // BLOQUEARCHIVO_H
