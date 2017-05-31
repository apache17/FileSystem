#include "api.h"

API::API(){

}

void API::crearDiscoVirtual()
{
    char * c = {"Disco Virtual"};
    Archivo * archivo = new Archivo(c,4194304);
    dv = new DiscoVirtual(archivo,4194304,4096);
    dv->formatear();
    addRoot();
}

void API::addRoot(){

    FileEntry *fe = new FileEntry();
    int pos = 1;
    char * ra = {"Raiz"};
    vector<Bloque*> lista = dv->getListaBloques();
    Bloque * bloque = lista[0];
    bloque = new BloqueFolder(ra,1);
    BloqueFolder * nRoot = dynamic_cast<BloqueFolder*>(bloque);
    dv->getMasterBlock()->setSiguienteDisponible(pos+2);
    dv->listaBloqueFolder.push_back(nRoot);
    this->root = nRoot;
}

Bloque * API::crearArchivo(char * nombre, BloqueFolder * actual, char * contenido)
{
    Archivo * archivo = dv->getArchivo();
    int pos = dv->getMasterBlock()->getSigDisponible();
    vector<Bloque*> lista = dv->getListaBloques();
    Bloque * b = lista[pos-1];
    b = new BloqueArchivo(nombre,pos);
    BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
    int size = strlen(contenido)/4096;

    if(size<1)
    {
        dv->getMasterBlock()->setSiguienteDisponible(pos+1);
        archivo->escribir(contenido,pos*4096,strlen(contenido));
        ba->setFileEntry(nombre,pos,pos,false,strlen(contenido));
    }

    else if(size>=1)
    {
        if(strlen(contenido)%4096>0)
            size++;
        dv->getMasterBlock()->setSiguienteDisponible(pos+size);
        archivo->escribir(contenido,pos*4096,strlen(contenido));
        ba->setFileEntry(nombre,pos,pos+size,false,strlen(contenido));
        ba->setFileEntry(nombre,pos,pos,false,strlen(contenido));
        actual->agregarFileEntry(ba->getFileEntry());
    }

    dv->listaBloqueArchivo.push_back(ba);
    return ba;
}

Bloque * API::crearFolder(char * nombre,BloqueFolder * actual)
{
    Archivo * archivo = dv->getArchivo();
    int pos = dv->getMasterBlock()->getSigDisponible();
    vector<Bloque*> lista = dv->getListaBloques();
    Bloque * b = lista[pos-1];
    b = new BloqueFolder(nombre,pos);
    dv->getMasterBlock()->setSiguienteDisponible(pos+1);
    BloqueFolder * bf = dynamic_cast<BloqueFolder*>(b);
    bf->setFileEntry(nombre,pos,pos,true,0);
    actual->agregarFileEntry(bf->getFileEntry());
    dv->listaBloqueFolder.push_back(bf);
    return bf;
}

void API::printRoot(){
    vector<FileEntry*> rootEntries = root->getListaEntries();
    for(int x = 0;x<rootEntries.size();x++)
    {
        rootEntries[x]->imprimirEntry();
        cout<<""<<endl;
    }

}

void API::dir()
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
        for(int x = 0;x<listaE.size();x++)
        {
            listaE[x]->imprimirEntry();
            cout<<""<<endl;
        }
        cout<<"--------------------------------------"<<endl;

    }
}

