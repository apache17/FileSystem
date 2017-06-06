#include "Archivo.h"

Archivo::Archivo(char * nombre,long size)
{
    this->nombre = nombre;

    file = fopen(this->nombre,"r+");
    fseek(file,size,SEEK_SET);
    fputc('\0',file);
    fclose(file);
}

void Archivo::abrir(){
    file = fopen(nombre, "r+");
}

char * Archivo::leer(int pos, int longitud){
    file = fopen("DiscoVirtual.txt","r+");
    fseek(file, pos, SEEK_SET);
    char * data = new char[longitud];
    fread(data, sizeof(char), longitud, file);
    return data;
}

void Archivo::escribir(char * data,int pos,int longitud){
    abrir();
    fseek(file, pos, SEEK_SET);
    fwrite(data, sizeof(char), longitud, file);
    cerrar();
}

void Archivo::setTamano(long pos){
    abrir();
    fseek(file, pos, SEEK_SET);
    fputc('\0', file);
    cerrar();
}

void Archivo::cerrar(){
    fclose(file);
}
