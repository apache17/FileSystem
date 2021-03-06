#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include <stdio.h>
#include "bloque.h"
#include "FileEntry.h"
using namespace std;

class BloqueArchivo
{
    public:
        BloqueArchivo(char * nombre, int numB, int tamB,Archivo * archivo);
        int getTamanoBloque();
        int getNumBloque();
        char * getNombre();
        void setNombre(char * nombre);
        FileEntry * getFileEntry();
        void setFileEntry(char* n, int fB, int lB, bool isF, int s);
        bool getEscritura();
        void setEscritura(bool escritura);
        Archivo * getArchivo();
        char * leer();
        char * nombre;

    private:
        void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;

        FileEntry *fe;
        Archivo * archivo;
};

#endif // BLOQUEARCHIVO_H
