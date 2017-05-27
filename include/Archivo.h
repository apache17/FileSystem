#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Archivo{
    public:
        Archivo(char* d);
        char * direccion;
        FILE* file;
        bool abierto;
        long tamano;

        FILE * abrir();
        void escribir(char * data);
        char * leer(int pos, int longi);
        void cerrar();
        int getSize();

};
#endif // ARCHIVO_H
