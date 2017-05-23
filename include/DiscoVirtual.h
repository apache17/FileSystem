#ifndef DISCOVIRTUAL_H
#define DISCOVIRTUAL_H

#include <stdio.h>
#include <list>
#include "Archivo.h"
#include "MasterBlock.h"
#include "BloqueFolder.h"
#include "BloqueArchivo.h"

class DiscoVirtual{
public:
    DiscoVirtual(Archivo * arch, int tamArchivo, int tamBloque);
    int tamArchivo,tamBloque;
    DiscoVirtual * crearDiscoVirtual(char * nombreArchivo);
    void formatear();
    void cargar();

    list<Archivo*> * listarArchivosEnRaiz();

    Archivo * archivo;
    MasterBlock * mb;
};


#endif // DISCOVIRTUAL_H
