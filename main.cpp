#include <iostream>
#include "api.h"
using namespace std;
#include "DiscoVirtual.h"
#include "MasterBlock.h"
#include "Archivo.h"
#include "masterblock.h"

int main()
{
    char * hola = {"Boris"};
    char * hola3 = {"Boris2"};
    char * hola2 = {"Boris Roldan Garcia Pacheco"};
    Archivo * archivo = new Archivo(hola);
    archivo->escribir(hola2);

    Archivo * archivo2 = new Archivo(hola3);

    DiscoVirtual * dv = new DiscoVirtual(archivo2,4194304,4096);
    dv->formatear(hola3);

    API * api = new API();
    api->addBloque(archivo,"Archivo",dv);

    Bloque * b = api->get(dv->getListaBloques(),0);
    BloqueArchivo * ba = reinterpret_cast<BloqueArchivo*>(b);


    return 0;
}
