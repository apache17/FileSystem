#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Archivo{
    public:
        Archivo(char * nombre, long size);
        void abrir();
        char * leer(int pos, int longitud);
        void escribir(char * data,int pos,int longitud);
        void cerrar();
        void setTamano(long pos);

    private:
        FILE * file;
        char * nombre;

};
#endif // ARCHIVO_H
