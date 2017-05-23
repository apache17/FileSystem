#ifndef MASTERBLOCK_H
#define MASTERBLOCK_H

#include "BloqueArchivo.h"
#include "Archivo.h"

#include <stdio.h>
#include <string.h>


class MasterBlock{
    public:
        MasterBlock(Archivo * arch, int tam, int cantB, int first, int sigDisp);
        Archivo * archivo;
        int tamanoBloque;
        int cantBloques;
        int primero;
        int sigDisponible;

        void cargar();
        void guardar();

    private:
        MasterBlock * charToMasterBlock(char * c);
        char * masterBlockToChar();
        void initFromChar(char * d);

    //cantidad de bloques para un archivo = tamaño de archivo / cantidad de bloques
};

#endif // MASTERBLOCK_H
