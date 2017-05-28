#ifndef DISCOVIRTUAL_H
#define DISCOVIRTUAL_H
#include <vector>
#include <stdio.h>
#include <list>
#include "Archivo.h"
#include "MasterBlock.h"
#include "BloqueFolder.h"
#include "BloqueArchivo.h"

class DiscoVirtual{
public:
    DiscoVirtual(Archivo * arch,int tamArc,int tamBlo);
    Bloque * asignarSiguienteBloque(int numeroBloque);
    void formatear(char *nombreArchivo);

    void cargar();
    void guardar();

    vector<FileEntry*> * listarArchivosEnRaiz();

    int getTamanoArchivo();
    int getTamanoBloque();
    Archivo * getArchivo();
    MasterBlock * getMasterBlock();
    vector<Bloque*> getListaBloques();
    vector<BloqueArchivo*> listaBloqueArchivo;
    vector<BloqueArchivo*> listaBloqueFolder;
private:
    vector<Bloque*> listaBloques;
    int tamArchivo,tamBloque;
    Archivo * archivo;
    MasterBlock * mb;
};


#endif // DISCOVIRTUAL_H
