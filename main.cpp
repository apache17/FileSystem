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
    dv->crearDiscoVirtual(hola);
    dv->formatear();

    Archivo * arch2 = new Archivo(hola,hola,true,5000);
    API * api = new API();
    api->addBloque(arch2,"Archivo");

    return 0;
}
