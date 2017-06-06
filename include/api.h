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
        void dirFolderActual();
        void printRoot();
        void crearDiscoVirtual();

        BloqueArchivo * crearArchivo(char * nombre, BloqueFolder * actual, char * contenido);
        BloqueFolder * crearFolder(char * nombre,BloqueFolder * actual,int x);

        void escribirEntries(FileEntry *fe,BloqueFolder * actual);
        void addRoot();
        BloqueFolder * root;
        DiscoVirtual * dv;
        int abrirFolder(char * n);
        int leerArchivo(char * n,BloqueFolder * bf);
        int initFromChar();
        void guardarEntries();

    protected:

    private:
        int rootSize;
};

#endif // API_H
