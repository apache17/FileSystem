#include "Archivo.h"

Archivo::Archivo(char * d,bool t,long tamano){
    direccion = d;
    abierto = false;
    tipo = t;

    if(strlen(direccion) > 0) {
        file = fopen(direccion,"w");
        fseek(file, tamano, SEEK_SET);
        fputc( '\0', file);
        fclose(file);
    }
}

void Archivo::abrir(){
    if(!abierto)
    {
        if(strlen(direccion)> 0)
            file = fopen(direccion,"a+");
        abierto = true;
    }
}

void Archivo::cerrar(){
    if(abierto)
    {
        fclose(file);
        abierto = false;
    }
}


void Archivo::escribir(int pos, char *data, int longi){
    if(!abierto)
        cout<<"Archivo Cerrado"<<endl;

    else
    {
        if(file != NULL)
        {
            fseek(file, pos, SEEK_SET );
            fwrite( data, 1, longi, file);
        }
    }
}

char * Archivo::leer(int pos, int longi){
    char * temp = new char[longi];
    if(!abierto)
        cout<<"Archivo Cerrado"<<endl;

    if(file != NULL) {
        char* data =  new char[longi];
        fseek(file, pos, SEEK_SET );
        fwrite(data,1,longi, file);
        return data;
    }
    return temp;
}

