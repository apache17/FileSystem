#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include <stdio.h>
#include "bloque.h"
#include "FileEntry.h"
using namespace std;

class BloqueArchivo:public Bloque
{
    public:
        BloqueArchivo(char * nombre, int numB);
        int getTamanoBloque();
        int getNumBloque();
        char * getNombre();
        FileEntry * getFileEntry();
        void setFileEntry(char* n, int fB, int lB, bool isF, int s);
        void imprimirContenido();
        bool getEscritura();
        void setEscritura(bool escritura);

    private:
        void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        FileEntry *fe;


};

#endif // BLOQUEARCHIVO_H
