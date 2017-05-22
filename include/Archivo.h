#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>
#include <iostream>
using namespace std;

class Archivo{
    public:
        Archivo(string d,bool t);
        string direccion;
        char * escritura;
        char * apuntador;
        bool tipo;

        void abrir();
        void escribir(int pos, char * data, int longi);
        char * leer(int pos, int longi);
        void cerrar();

        int seek(int posDesde, int cuantosAMoverse);

        bool abierto,cerrado;

};

#endif // ARCHIVO_H
