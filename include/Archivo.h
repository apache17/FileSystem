#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Archivo{
    public:
        Archivo(char* d,bool t,long tamano);

        char * direccion;
        FILE* file;
        bool tipo;
        bool abierto;
        long tamano;

        void abrir();
        void escribir(int pos, char * data, int longi);
        char * leer(int pos, int longi);
        void cerrar();
};

#endif // ARCHIVO_H
