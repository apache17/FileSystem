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
    Archivo * archivo = new Archivo(hola);
    DiscoVirtual * dv = new DiscoVirtual(archivo,4194304,4096);
    dv->formatear(hola);

    char * hola1 = {"Boris"};
    char * hola2 = {"Boris Garcia"};
    char * hola3 = {"Boris Garcia Pacheco"};
    char * hola4 = {"Garcia Pacheco"};
    char * hola5 = {"Garcia"};
    char * hola6 = {"Pacheco"};

    Archivo * archivo1 = new Archivo(hola1);
    Archivo * archivo2 = new Archivo(hola2);
    Archivo * archivo3 = new Archivo(hola3);
    Archivo * archivo4 = new Archivo(hola4);
    Archivo * archivo5 = new Archivo(hola5);
    Archivo * archivo6 = new Archivo(hola6);

    archivo1->escribir(hola1);
    archivo2->escribir(hola2);
    archivo3->escribir(hola3);
    archivo4->escribir(hola4);
    archivo5->escribir(hola5);
    archivo6->escribir(hola6);

    api->addBloque(archivo1,"Archivo",dv);
    api->addBloque(archivo2,"Archivo",dv);
    api->addBloque(archivo3,"Archivo",dv);
    api->addBloque(archivo4,"Archivo",dv);
    api->addBloque(archivo5,"Folder",dv);
    api->addBloque(archivo6,"Folder",dv);

    api->dir(dv);

    return 0;
}
