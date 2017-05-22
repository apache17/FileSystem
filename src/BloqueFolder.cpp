#include "BloqueFolder.h"

BloqueFolder::BloqueFolder()
{
    //ctor
}

void BloqueFolder::cargar()
{
    this->archivo->abrir();
    char * data = archivo->leer(0, tamanoBloque);
    initFromChar(data);
}
