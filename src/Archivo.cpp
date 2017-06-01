#include "Archivo.h"

Archivo::Archivo(char * d,long size)
{
    direccion = d;
    abierto = false;
    size = size;

    if(strlen(this->direccion)> 0) {
        file = fopen(this->direccion,"w");
        fseek(file,size,SEEK_SET);
        fputc('\0',file);
        fclose(file);
    }
}

int Archivo::getSize()
{
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
    return NULL;
}

void Archivo::cerrar(){
    if(abierto)
    {
        fclose(file);
        abierto = false;
    }
}

int Archivo::escribir(char *data, int pos, int longitud)
{
   int x;
   file = fopen(direccion,"w+");
   if(file != NULL){
        fseek( this->file, pos, SEEK_SET );
        x = fwrite(data,sizeof(char), longitud, file);
   }
   return x;
}

char * Archivo::leer(int pos, int longi)
{
    file = fopen(direccion,"r");
    char * buffer;
    int result;
    buffer = (char*) malloc (sizeof(char)*longi);
    if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
    result = fread (buffer,1,longi,file);
    if (result != longi) {fputs (":(",stderr); exit (3);}
    fclose (file);
    return(buffer);
}

