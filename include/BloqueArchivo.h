#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include <stdio.h>
#include "Archivo.h"
class BloqueArchivo
{
    public:
        BloqueArchivo(char * nombre, int numB, Archivo * a,int tamanoB);
        int getTamanoBloque();
        int getNumBloque();
        char * getNombre();
        Archivo * getArchivo();
        void guardar();

    private:
        void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        Archivo * archivo;
};

#endif // BLOQUEARCHIVO_H
