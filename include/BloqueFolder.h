#ifndef BLOQUEFOLDER_H
#define BLOQUEFOLDER_H

#include <stdio.h>
#include "Archivo.h"

class BloqueFolder{
public:
    BloqueFolder(string direccion, int numBloque, Archivo * arch);
    string direccion;
    int numBloque;
    Archivo * archivo;

    list<Archivo*> entriesList;

    void cargar();

private:
    void initFromChar(char * d);
};

#endif // BLOQUEFOLDER_H
