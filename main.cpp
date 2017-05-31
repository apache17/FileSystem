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
    char * contenido = {"Hola Mundo"};

    api->crearFolder(nombre,api->root);
    api->crearArchivo(nombre,api->root,contenido);

    api->printRoot();

}
