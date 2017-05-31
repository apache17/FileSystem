#include <iostream>
#include "api.h"
using namespace std;
#include "DiscoVirtual.h"
#include "MasterBlock.h"
#include "Archivo.h"
#include "masterblock.h"

int main()
{
    API * api = new API();
    api->crearDiscoVirtual();

    char * nombre = {"Mis Documentos"};
    char * nombre2 = {"Funciona"};
    char * nombre3 = {"Funciona esta Mierda?"};
    char * contenido = {"Hola Mundo"};

    api->crearFolder(nombre,api->root);
    api->crearArchivo(nombre2,api->root,contenido);

    api->printRoot();

    vector<BloqueFolder*> lista = api->dv->listaBloqueFolder;
    api->crearFolder(nombre2,lista[1]);
    api->crearArchivo(nombre3,lista[1],contenido);
    vector<FileEntry*> listaE = lista[1]->getListaEntries();
    listaE[1]->imprimirEntry();

}
