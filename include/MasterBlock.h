#ifndef MASTERBLOCK_H
#define MASTERBLOCK_H
#include <stdio.h>
#include "BloqueArchivo.hpp"
#include "Archivo.hpp"

class MasterBlock{
    public:
        MasterBlock(Archivo * arch, int tam, int cantB, int first, int sigDisp);

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
