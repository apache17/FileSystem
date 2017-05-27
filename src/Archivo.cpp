#include "Archivo.h"

Archivo::Archivo(char * d)
{
    direccion = d;
    abierto = false;
}

int Archivo::getSize()
{
    abrir();
    fseek (file , 0 , SEEK_END);
    tamano = ftell (file);
    rewind (file);
    return tamano;
}

FILE * Archivo::abrir()
{
    if(!abierto)
    {
        if(strlen(direccion)> 0)
        {
            file = fopen(direccion,"a+");
            abierto = true;
            rewind (file);
            return file;
        }
    }
}

void Archivo::cerrar(){
    if(abierto)
    {
        fclose(file);
        abierto = false;
    }
}

void Archivo::escribir(char *data)
{
   abrir();
   if(file != NULL)
        fwrite(data,sizeof(char), strlen(data), file);
}

char * Archivo::leer(int pos, int longi)
{
    long lSize = longi - pos;
    char * buffer = new char[lSize];
    size_t result;
    fopen(direccion,"r+");
    result = fread (buffer,pos,lSize,file);
    if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
    cerrar();
    return buffer;
}

