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
        Bloque * get(vector<Bloque*> lista,int i);
        Bloque *  addBloque(DiscoVirtual * dv,char * nombre, string tipo,char * data);
        void addData(DiscoVirtual * dv,char * data,BloqueFolder *bf,char * nombre);
        void dir(DiscoVirtual * dv);

    protected:

    private:
};

#endif // API_H
