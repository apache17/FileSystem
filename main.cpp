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



    vector<BloqueFolder*> lista = api->dv->listaBloqueFolder;
    api->crearArchivo(nombre2,lista[1],contenido);
    api->crearArchivo(nombre3,lista[1],contenido);

    api->dir();
    /*Archivo * arch = api->dv->getArchivo();
    char * c = arch->leer(4096,11);

    for(int x = 0;x<strlen(c);x++)
        cout<<c[x];*/
}
