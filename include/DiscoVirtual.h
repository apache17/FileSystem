#ifndef DISCOVIRTUAL_H
#define DISCOVIRTUAL_H

#include <stdio.h>
#include <list>
#include "Archivo.hpp"
#include "MasterBlock.hpp"
#include "BloqueFolder.hpp"

class DiscoVirtual{
public:
    DiscoVirtual(Archivo * arch, const int tamArchivo, const int tamBloque);
    DiscoVirtual * crearDiscoVirtual(char * nombreArchivo);
    void formatear();
    void cargar();

    BloqueFolder * listarArchivosEnRaiz();

    Archivo * archivo;
    MasterBlock * mb;
};


#endif // DISCOVIRTUAL_H
