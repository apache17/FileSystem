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
    void formatear();
    void cargar();
    vector<FileEntry*> listarArchivosEnRaiz();

    int getTamanoArchivo();
    int getTamanoBloque();
    BloqueFolder * getFolderActual();
    void setFolderActual(BloqueFolder * bf);
    Archivo * getArchivo();
    MasterBlock * getMasterBlock();
    BloqueFolder * getRaiz();
    void setRaiz(BloqueFolder * bf);

    vector<Bloque*> getListaBloques();
    vector<BloqueArchivo*> listaBloqueArchivo;
    vector<BloqueFolder*> listaBloqueFolder;

private:
    vector<Bloque*> listaBloques;
    int tamArchivo,tamBloque;
    Archivo * archivo;
    MasterBlock * mb;
    BloqueFolder * raiz;
    BloqueFolder * folderActual;
};


#endif // DISCOVIRTUAL_H
