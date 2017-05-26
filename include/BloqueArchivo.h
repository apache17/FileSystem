#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include <stdio.h>
#include "bloque.h"

class BloqueArchivo:public Bloque
{
    public:
        BloqueArchivo(char * nombre, int numB, Archivo * a,int tamanoB, bool disp);
        int getTamanoBloque();
        int getNumBloque();
        char * getNombre();
        bool getDisponible();
        Archivo * getArchivo();
        void guardar();

    private:
        void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        bool disponible;
        Archivo * archivo;
};

#endif // BLOQUEARCHIVO_H
