#ifndef API_H
#define API_H
#include "MasterBlock.h"
#include "BloqueArchivo.h"
#include "BloqueFolder.h"
#include "archivo.h"
#include "DiscoVirtual.h"

class API
{
    public:
        API();

        void dir();
        void printRoot();
        void crearDiscoVirtual();

        Bloque * crearArchivo(char * nombre, BloqueFolder * actual, char * contenido);
        Bloque * crearFolder(char * nombre,BloqueFolder * actual);

        void addRoot();
        BloqueFolder * root;
        DiscoVirtual * dv;

    protected:

    private:
};

#endif // API_H
