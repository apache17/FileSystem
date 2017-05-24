#include "bloque.h"

Bloque::Bloque(char * nombre, int numB, Archivo * a,int tamanoB)
{
   nombre = nombre;
    numBloque = numB;
    archivo = a;
    tamanoBloque = tamanoB;
}

void Bloque::guardar()
{

}

void Bloque::initFromChar(char * d)
{

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
