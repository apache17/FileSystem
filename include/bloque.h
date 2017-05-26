#ifndef BLOQUE_H
#define BLOQUE_H
#include "Archivo.h"

class Bloque
{
    public:
        Bloque(char * nombre, int numB,int tamanoB,bool disp );
        virtual int getTamanoBloque();
        virtual int getNumBloque();
        virtual char * getNombre();
        virtual bool getDisponible();
        virtual void setFileEntry(char* nombre, int firstBlock, int lastBlock, int isFolder, int size);

    private:
        virtual void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        bool disponible;
};

#endif // BLOQUE_H
