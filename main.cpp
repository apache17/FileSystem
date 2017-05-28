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

    Bloque * b = api->addBloque(archivo,"Archivo",dv);
    Bloque * b2 = api->addBloque(archivo2,"Archivo",dv);
    Bloque * b3 = api->addBloque(archivo2,"Archivo",dv);

    BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
    BloqueArchivo * ba2 = dynamic_cast<BloqueArchivo*>(b2);

    cout<<ba->getFileEntry()->getSize()<<endl;
    cout<<ba2->getFileEntry()->getSize()<<endl;

    vector<BloqueArchivo*> lista = dv->listaBloqueArchivo;
    BloqueArchivo * b4= lista[0];
    cout<<b4->getFileEntry()->getSize()<<endl;
    return 0;
}
