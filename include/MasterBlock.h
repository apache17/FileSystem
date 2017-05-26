#ifndef MASTERBLOCK_H
#define MASTERBLOCK_H

#include "BloqueArchivo.h"
#include "Archivo.h"
#include <stdio.h>
#include <string.h>

class MasterBlock{
    public:
        MasterBlock(Archivo * arch, int tam, int cantB, int first, int sigDisp);
        Archivo * getArchivo();
        int getTamanoBloque();
        int getCantBloques();
        int getPrimerBloque();
        int getSigDisponible();
        void setSiguienteDisponible(int x);
        void cargar();
        void guardar();

    private:
        MasterBlock * charToMasterBlock(char * c);
        char * masterBlockToChar();
        void initFromChar(char * d);
        Archivo * archivo;
        int tamanoBloque;
        int cantBloques;
        int primero;
        int sigDisponible;
};

#endif // MASTERBLOCK_H
