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
        virtual void guardar();
        virtual bool getDisponible();

    private:
        virtual void initFromChar(char * d);
        int tamanoBloque;
        int numBloque;
        char * nombre;
        bool disponible;
};

#endif // BLOQUE_H
