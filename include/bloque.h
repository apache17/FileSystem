#ifndef BLOQUE_H
#define BLOQUE_H
#include "Archivo.h"

class Bloque
{
    public:
        Bloque(char * nombre, int numB, Archivo * a,int tamanoB );
        virtual int getTamanoBloque();
        virtual int getNumBloque();
        virtual char * getNombre();
        virtual Archivo * getArchivo();
        virtual void guardar();

    private:
        virtual void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        Archivo * archivo;
};

#endif // BLOQUE_H
