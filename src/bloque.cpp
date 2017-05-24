#include "bloque.h"

Bloque::Bloque(char * nombre, int numB, Archivo * a,int tamanoB)
{
   nombre = nombre;
    numBloque = numB;
    archivo = a;
    tamanoBloque = tamanoB;
}

Bloque::~Bloque()
{
    //dtor
}

char * Bloque::getNombre()
{
    return nombre;
}

int Bloque::getNumBloque()
{
    return numBloque;
}

int Bloque::getTamanoBloque()
{
    return tamanoBloque;
}

Archivo * Bloque::getArchivo()
{
    return archivo;
}
