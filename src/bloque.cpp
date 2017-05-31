#include "bloque.h"

Bloque::Bloque(char * nombre, int numB,int tamB)
{
    nombre = nombre;
    numBloque = numB;
    tamanoBloque = tamB;
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


