#ifndef BLOQUEFOLDER_H
#define BLOQUEFOLDER_H

#include <stdio.h>
#include "Archivo.h"

class BloqueFolder{
    public:

        BloqueFolder();
        Archivo * archivo;
        void cargar();
};

#endif // BLOQUEFOLDER_H
