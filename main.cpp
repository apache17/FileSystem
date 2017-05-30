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

    char * hola = {"Disco Virtual"};
    char * hola1 = {"Mis Documentos"};
    Archivo * archivo = new Archivo(hola,4194304);
    DiscoVirtual * dv = new DiscoVirtual(archivo,4194304,4096);
    dv->formatear(hola);

    api->addBloque(dv,hola1,"Archivo");
    api->addBloque(dv,hola1,"Folder");

    vector<BloqueArchivo*> lista = dv->listaBloqueArchivo;
    BloqueArchivo * ba = lista[0];

    vector<BloqueFolder*> lista2 = dv->listaBloqueFolder;
    BloqueFolder * bf = lista2[0];

    api->addDataAArchivo(dv,hola1,ba);
    api->addDataAFolder(dv,hola1,bf,hola1);
    api->dir(dv);
}
