#ifndef BLOQUEFOLDER_H
#define BLOQUEFOLDER_H

#include <stdio.h>
#include "Archivo.h"
#include <iostream>
#include <list>
#include <string.h>

class BloqueFolder{
public:
    BloqueFolder(string dir, int numB, Archivo * a,int tamanoB);
    string direccion;
    int numBloque;
    Archivo * archivo;
    int tamanoBloque;

    list<Archivo*> entriesList;

    void cargar();

private:
    void initFromChar(char * d);
};

#endif // BLOQUEFOLDER_H
