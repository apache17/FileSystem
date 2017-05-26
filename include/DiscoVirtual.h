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
    Bloque * asignarSiguienteBloque(int numeroBloque);
    void formatear();
    void cargar();

    list<Archivo*> * listarArchivosEnRaiz();

    int getTamanoArchivo();
    int getTamanoBloque();
    Archivo * getArchivo();
    MasterBlock * getMasterBlock();
    list<Bloque*> getListaBloques();

private:
    list<Bloque*> listaBloques;
    int tamArchivo,tamBloque;
    Archivo * archivo;
    MasterBlock * mb;
};


#endif // DISCOVIRTUAL_H
