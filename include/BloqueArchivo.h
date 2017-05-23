#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include <stdio.h>

class BloqueArchivo
{
    public:
        BloqueArchivo();
        BloqueArchivo * asignarSiguienteBloque();
        virtual ~BloqueArchivo();

    protected:

    private:
};

#endif // BLOQUEARCHIVO_H
