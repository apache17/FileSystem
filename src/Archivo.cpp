#include "Archivo.h"

Archivo::Archivo(char * d,long size)
{
    direccion = d;
    abierto = false;
    size = size;

    if(strlen(this->direccion)> 0) {
        file = fopen(this->direccion,"w");
        fputc('\0',file);
        fclose(file);
    }
}

int Archivo::getSize()
{
    abrir();
    fseek (file , 0 , SEEK_END);
    size = ftell (file);
    rewind (file);
    return size;
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

void Archivo::escribir(char *data, int pos, int longitud)
{
   abrir();
   if(file != NULL){
        fseek( this->file, pos, SEEK_SET );
        fwrite(data,sizeof(char), longitud, file);
   }
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

