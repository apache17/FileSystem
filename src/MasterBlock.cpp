#include "MasterBlock.h"

MasterBlock::MasterBlock(Archivo * arch, const int tam, int cantB, int first,int sigDisp){
    archivo = arch;
    tamanoBloque = tam;
    cantBloques = cantB;
    primero = first;
    sigDisponible = sigDisp;
}

void MasterBlock::cargar(){
    this->archivo->abrir();
    char * data = archivo->leer(0, tamañoBloque);
    initFromChar(data);
}

void MasterBlock::guardar(){

}

MasterBlock * MasterBlock::charToMasterBlock(char * c){

}

char * MasterBlock::masterBlockToChar(){

}

void MasterBlock::initFromChar(char * d){
    int pos = 0;

    memcpy(&this->tamañoBloque, &d[pos], 4);
    pos+=4;
    memcpy(&this->cantBloques, &d[pos], 4);
    pos+=4;
    memcpy(&this->primero, &d[pos], 4);
    pos+=4;
    memcpy(&this->sigDisponible, &d[pos], 4);
    pos+=4;
}
