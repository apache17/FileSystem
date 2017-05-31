#ifndef BLOQUE_H
#define BLOQUE_H
#include "Archivo.h"

class Bloque
{
    public:
        Bloque(char * nombre, int numB,int tamB);
        virtual int getTamanoBloque();
        virtual int getNumBloque();
        virtual char * getNombre();

    private:
        virtual void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
};

#endif // BLOQUE_H
