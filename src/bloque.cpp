#include "bloque.h"

Bloque::Bloque(char * nombre, int numB,int tamanoB)
{
    nombre = nombre;
    numBloque = numB;
    tamanoBloque = tamanoB;

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


