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


        Bloque * get(list<Bloque*>,int _i);
        Bloque *  addBloque(Archivo * arch, string tipo, DiscoVirtual * dv);
        void dir(DiscoVirtual * dv);

    protected:

    private:
};

#endif // API_H
