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
    Archivo * archivo = new Archivo(hola,4194304);
    DiscoVirtual * dv = new DiscoVirtual(archivo,4194304,4096);
    dv->formatear(hola);

    char * hola1 = {"Boris"};
    char * hola2 = {"Roldan"};
    char * hola3 = {"Garcia"};
    char * hola4 = {"Pacheco"};

    archivo->escribir(hola,2000,strlen(hola));
    api->addBloque("Archivo",dv,hola2,hola1);
    api->addBloque("Archivo",dv,hola2,hola1);
    api->dir(dv);

    //char * n = dv->getArchivo()->leer(4096,6);
    return 0;
}
