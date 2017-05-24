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

    DiscoVirtual * crearDiscoVirtual(char * nombreArchivo);
    BloqueArchivo * asignarSiguienteBloque();
    void formatear();
    void cargar();

    list<FileEntry*> * listarArchivosEnRaiz();

    int getTamanoArchivo();
    int getTamanoBloque();
    Archivo * getArchivo();
    MasterBlock * getMasterBlock();

private:
    int tamArchivo,tamBloque;
    Archivo * archivo;
    MasterBlock * mb;
};


#endif // DISCOVIRTUAL_H
