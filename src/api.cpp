#include "api.h"

API::API(){

}

Bloque * API::get(vector<Bloque*> lista, int i){
    return lista[i];
}

void API::addData(BloqueFolder * bf,char * data,char * nombre)
{
    Archivo * archivo = bf->getArchivo();
    vector<FileEntry*> lista = bf->getListaEntries();
    int x = lista.size();
    FileEntry * fe = lista[x-1];

    if(bf->getEspacioUtilizado()+ strlen(data) <= 4096)
    {
        bf->setEspacioUtilizado(strlen(data));
        archivo->escribir(data);
        bf->agregarFileEntry(nombre,fe->getFirstBLock(),fe->getLastBlock(),false,strlen(data),fe->getPosFinal()+1,fe->getPosFinal()+1+strlen(data));
    }

}

Bloque * API::addBloque(Archivo *arch, string tipo, DiscoVirtual * dv)
{
    if(tipo == "Archivo")
    {
        int pos = dv->getMasterBlock()->getSigDisponible();
        vector<Bloque*> lista = dv->getListaBloques();
        Bloque * b = lista[pos];
        int size = arch->getSize()/4096;

        if(size<1){
            b = new BloqueArchivo(arch->direccion,pos,arch,arch->getSize(),false);
            dv->getMasterBlock()->setSiguienteDisponible(pos+1);
            BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
            ba->setFileEntry(arch->direccion,pos,pos,false,arch->getSize());
            dv->listaBloqueArchivo.push_back(ba);
            return ba;
        }
        else if(size>=1)
        {
            if(arch->getSize()%4096>0)
                size++;
            b = new BloqueArchivo(arch->direccion,pos,arch,arch->getSize(),1);
            BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
            dv->getMasterBlock()->setSiguienteDisponible(pos+size);
            ba->setFileEntry(arch->direccion,pos,pos+size-1,false,arch->getSize());
            dv->listaBloqueArchivo.push_back(ba);
            return ba;
        }
    }
    else if(tipo == "Folder")
    {
        int pos = dv->getMasterBlock()->getSigDisponible();
        vector<Bloque*> lista = dv->getListaBloques();
        Bloque * b = lista[pos];
        int size = arch->getSize()/4096;

        if(size<1){

            b = new BloqueFolder(arch->direccion,pos,arch,arch->getSize(),false);
            dv->getMasterBlock()->setSiguienteDisponible(pos+1);
            BloqueFolder * bf = dynamic_cast<BloqueFolder*>(b);
            bf->setEspacioUtilizado(arch->getSize());
            bf->agregarFileEntry(arch->direccion,pos,pos,true,arch->getSize(),0,arch->getSize());
            dv->listaBloqueFolder.push_back(bf);
            bf->setNombre(arch->direccion);
            return bf;
        }
        else if(size>=1)
        {
            if(arch->getSize()%4096>0)
                size++;
            b = new BloqueFolder(arch->direccion,pos,arch,arch->getSize(),1);
            BloqueFolder * bf = dynamic_cast<BloqueFolder*>(b);
            bf->setEspacioUtilizado(arch->getSize());
            dv->getMasterBlock()->setSiguienteDisponible(pos+size);
            bf->agregarFileEntry(arch->direccion,pos,pos+size-1,true,arch->getSize(),0,arch->getSize());
            dv->listaBloqueFolder.push_back(bf);
            bf->setNombre(arch->direccion);
            return bf;
        }

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
        cout<<""<<endl;
        for(int x = 0;x<listaE.size();x++)
        {
            listaE[x]->imprimirEntry();
            cout<<"Espacio Utilizado : ";
            cout<<bf->getEspacioUtilizado()<<endl;
            cout<<""<<endl;
        }
        cout<<"--------------------------------------"<<endl;

    }
}

