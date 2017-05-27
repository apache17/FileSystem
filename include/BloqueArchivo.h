#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include <stdio.h>
#include "bloque.h"
#include "FileEntry.h"

class BloqueArchivo:public Bloque
{
    public:
        BloqueArchivo(char * nombre, int numB, Archivo * a,int tamanoB, bool disp);
        int getTamanoBloque();
        int getNumBloque();
        char * getNombre();
        bool getDisponible();
        Archivo * getArchivo();
        FileEntry * getFileEntry();
        void setFileEntry(char* n, int fB, int lB, int isF, int s);



    private:
        void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        bool disponible;
        Archivo * archivo;
        FileEntry *fe;
};

#endif // BLOQUEARCHIVO_H
