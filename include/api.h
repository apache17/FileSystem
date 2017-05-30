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

        void dir(DiscoVirtual * dv);
        void printRoot();

        Bloque *  addBloque(DiscoVirtual * dv,char * nombre, string tipo);
        void addDataAFolder(DiscoVirtual * dv,char * data,BloqueFolder *bf,char * nombre);
        void addDataAArchivo(DiscoVirtual * dv,char * data,BloqueArchivo *ba);
        Bloque * addRootBloque(DiscoVirtual * dv);

        BloqueFolder * root;

    protected:

    private:
};

#endif // API_H
