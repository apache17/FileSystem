#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Archivo{
    public:
        Archivo(char* d,long size);
        char * direccion;
        FILE* file;
        bool abierto;

        long size;

        FILE * abrir();
        int escribir(char * data, int pos, int longitud);
        char * leer(int pos, int longi);
        void cerrar();
        int getSize();

};
#endif // ARCHIVO_H
