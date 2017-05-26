#include "bloque.h"

Bloque::Bloque(char * nombre, int numB,int tamanoB,bool disp)
{
    nombre = nombre;
    numBloque = numB;
    tamanoBloque = tamanoB;
    disponible = disp;
}

void Bloque::guardar()
{

}

void Bloque::initFromChar(char * d)
{

}

bool Bloque::getDisponible()
{
    return disponible;
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


