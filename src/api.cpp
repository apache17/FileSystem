#include "api.h"

API::API(){

}

void API::addDataAArchivo(DiscoVirtual * dv,char * data,BloqueArchivo *ba)
{
    Archivo * archivo = dv->getArchivo();
    int pos = ba->getFileEntry()->getFirstBLock();
    int size = strlen(data)/4096;

    if(size<1)
    {
        dv->getMasterBlock()->setSiguienteDisponible(pos+1);
        archivo->escribir(data,pos*4096,strlen(data));
        ba->getFileEntry()->setSize(strlen(data));
    }

    else if(size>=1)
    {
        if(strlen(data)%4096>0)
            size++;
        dv->getMasterBlock()->setSiguienteDisponible(pos+size);
        archivo->escribir(data,pos*4096,strlen(data));
        ba->getFileEntry()->setLastBlock(pos+size);
        ba->getFileEntry()->setSize(strlen(data));
    }

}

void API::addDataAFolder(DiscoVirtual * dv,char * nombre,BloqueFolder * bf,char * data)
{
    Archivo * archivo = dv->getArchivo();
    vector<FileEntry*> lista = bf->getListaEntries();
    FileEntry * feN = new FileEntry();
    int pos = dv->getMasterBlock()->getSigDisponible();
    int size = strlen(data)/4096;

    if(size<1)
    {
        dv->getMasterBlock()->setSiguienteDisponible(pos+1);
        archivo->escribir(data,pos*4096,strlen(data));
        bf->agregarFileEntry(feN,nombre,pos,pos,false,strlen(data));
    }

    else if(size>=1)
    {
        if(strlen(data)%4096>0)
            size++;
        dv->getMasterBlock()->setSiguienteDisponible(pos+size);
        bf->agregarFileEntry(feN,nombre,pos,pos+size,false,strlen(data));
        archivo->escribir(data,pos*4096,strlen(data));
    }
}

Bloque * API::addRootBloque(DiscoVirtual * dv){
    return NULL;
}

void API::printRoot(){
    vector<FileEntry*> rootEntries = root->getListaEntries();
    for(int x = 0;x<rootEntries.size();x++)
    {
        rootEntries[x]->imprimirEntry();
        cout<<""<<endl;
    }

}

Bloque * API::addBloque(DiscoVirtual * dv,char * nombre, string tipo)
{
    Archivo * archivo = dv->getArchivo();
    if(tipo == "Archivo")
    {
        int pos = dv->getMasterBlock()->getSigDisponible();
        vector<Bloque*> lista = dv->getListaBloques();
        Bloque * b = lista[pos];
        b = new BloqueArchivo(nombre,pos,false);
        dv->getMasterBlock()->setSiguienteDisponible(pos+1);
        BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
        ba->setFileEntry(nombre,pos,pos,false,0);
        dv->listaBloqueArchivo.push_back(ba);
        return ba;
    }

    else if(tipo == "Folder")
    {
        FileEntry *fe = new FileEntry();
        int pos = dv->getMasterBlock()->getSigDisponible();
        vector<Bloque*> lista = dv->getListaBloques();
        Bloque * b = lista[pos];
        b = new BloqueFolder(nombre,pos);
        dv->getMasterBlock()->setSiguienteDisponible(pos+1);
        BloqueFolder * bf = dynamic_cast<BloqueFolder*>(b);
        bf->agregarFileEntry(fe,nombre,pos,pos,true,0);
        dv->listaBloqueFolder.push_back(bf);
        bf->setNombre(nombre);
        return bf;
    }
    return NULL;

}

void API::dir(DiscoVirtual * dv)
{
    vector<BloqueArchivo*> lista = dv->listaBloqueArchivo;
    vector<BloqueFolder*> lista2 = dv->listaBloqueFolder;
    cout<<"Bloques de Archivo"<<endl;
    cout<<""<<endl;

    for(int x = 0; x<lista.size();x++)
    {
        BloqueArchivo * ba = lista[x];
        ba->getFileEntry()->imprimirEntry();
        cout<<"--------------------------------------"<<endl;
        cout<<""<<endl;
    }

    cout<<""<<endl;
    cout<<"Bloques de Folder"<<endl;
    cout<<""<<endl;

    for(int x = 0; x<lista2.size();x++)
    {
        BloqueFolder * bf = lista2[x];
        vector<FileEntry*> listaE = bf->getListaEntries();
        cout<<""<<endl;
        cout<<"Entries de: ";
        bf->imprimirN();
        cout<<"Espacio Utilizado : ";
        cout<<bf->getEspacioUtilizado()<<endl;

        cout<<""<<endl;
        for(int x = 0;x<listaE.size();x++)
        {
            listaE[x]->imprimirEntry();
            cout<<""<<endl;
        }
        cout<<"--------------------------------------"<<endl;

    }
}

