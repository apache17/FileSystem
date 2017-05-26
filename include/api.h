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
        DiscoVirtual *disco;
        MasterBlock * mb;
        Bloque * get(list<Bloque*>,int _i);
        Bloque *  addBloque(Archivo * arch, string tipo);

    protected:

    private:
};

#endif // API_H
