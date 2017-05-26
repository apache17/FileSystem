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
    Archivo * arch = new Archivo(hola,hola,true,5000);
    DiscoVirtual * dv = new DiscoVirtual(arch,4000000,4000);
    dv->formatear();

    Archivo * arch2 = new Archivo(hola,hola,true,5000);
    char * hola1 = {"Boris Roldan Garcia Pacheco"};
    arch2->abrir();
    arch2->escribir(0,hola1,strlen(hola1));

    API * api = new API();
    api->addBloque(arch2,"Archivo",dv);

    Bloque * b = api->get(dv->getListaBloques(),0);
    BloqueArchivo * ba = reinterpret_cast<BloqueArchivo*>(b);
        return 0;
}
