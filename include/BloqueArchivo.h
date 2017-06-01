#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include <stdio.h>
#include "bloque.h"
#include "FileEntry.h"
using namespace std;

class BloqueArchivo:public Bloque
{
    public:
        BloqueArchivo(char * nombre, int numB, int tamB,Archivo * archivo);
        int getTamanoBloque();
        int getNumBloque();
        char * getNombre();
        FileEntry * getFileEntry();
        void setFileEntry(char* n, int fB, int lB, bool isF, int s);
        bool getEscritura();
        void setEscritura(bool escritura);
        Archivo * getArchivo();

    private:
        void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        FileEntry *fe;
        Archivo * archivo;


};

#endif // BLOQUEARCHIVO_H
