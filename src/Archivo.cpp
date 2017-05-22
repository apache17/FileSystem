#include "Archivo.h"

Archivo::Archivo(string d,bool t){
    direccion = d;
    abierto = false;
    cerrado = true;
    tipo = t;
    escritura = new char[100];
    apuntador = NULL;
}

void Archivo::abrir(){
    if(!abierto){
        abierto = true;
        cerrado = false;
    }
}

void Archivo::cerrar(){
    if(!cerrado){
        cerrado = true;
        abierto = false;
    }
}

int Archivo::seek(int posDesde, int posHasta){
    int a = 0;
    for(a = posDesde; a<posHasta; a++){
        apuntador = &escritura[a];
    }
    return a;
}

void Archivo::escribir(int pos, char *data, int longi){
    if(!abierto){
        cout<<"abrirlo"<<endl;
    }
    else{
        int currentPos = seek(0, pos);
        for(int b = currentPos; b<longi; b++){
            escritura[b] = data[b];
        }
    }
}

char * Archivo::leer(int pos, int longi){
    char * temp = new char[longi];
    if(!abierto)
        cout<<"abrirlo"<<endl;
    else{
        int currentPos = seek(0, pos);
        for(int a = currentPos; a<longi; a++){
            temp[a] = escritura[a];
        }
    }
    return temp;
}

