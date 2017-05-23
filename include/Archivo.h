#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>
#include <iostream>
using namespace std;

class Archivo{
    public:
        Archivo(string d,char * n,bool t);
        string direccion;
        char * nombre;
        bool tipo;

        char * escritura;
        char * apuntador;
        bool abierto,cerrado;

        void abrir();
        void escribir(int pos, char * data, int longi);
        char * leer(int pos, int longi);
        void cerrar();

        int seek(int posDesde, int cuantosAMoverse);
};

#endif // ARCHIVO_H
