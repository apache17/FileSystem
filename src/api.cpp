#include "api.h"

API::API(){

}

Bloque * API::get(vector<Bloque*> lista, int i){
    return lista[i];
}

void API::addData(DiscoVirtual * dv,char * nombre,BloqueFolder * bf,char * data)
{
    Archivo * archivo = dv->getArchivo();
    vector<FileEntry*> lista = bf->getListaEntries();
    int x = lista.size();
    FileEntry * fe = lista[x-1];
    FileEntry * feN = new FileEntry();

    int z = bf->getEspacioUtilizado()%4096;
    int y = (bf->getEspacioUtilizado()+strlen(data))/4096;

    if(y<1)
    {
        archivo->escribir(data,bf->getEspacioUtilizado(),strlen(data));
        bf->agregarFileEntry(feN,nombre,fe->getFirstBLock(),fe->getLastBlock(),false,strlen(data),fe->getPosFinal()+1,fe->getPosFinal()+strlen(data));
        bf->setEspacioUtilizado(strlen(data));
    }

    else if(y>=1)
    {
        if(strlen(data)%4096>0)
            y++;
        int pos = dv->getMasterBlock()->getSigDisponible();
        dv->getMasterBlock()->setSiguienteDisponible(pos+y);

        bf->agregarFileEntry(feN,nombre,pos,dv->getMasterBlock()->getSigDisponible()-1,false,strlen(data),fe->getPosFinal()+1,fe->getPosFinal()+strlen(data));
        archivo->escribir(data,pos*4096,strlen(data));

        bf->setEspacioUtilizado(strlen(data));

    }
}

Bloque * API::addBloque(DiscoVirtual * dv,char * nombre, string tipo,char * data)
{
    Archivo * archivo = dv->getArchivo();
    if(tipo == "Archivo")
    {
        int pos = dv->getMasterBlock()->getSigDisponible();
        vector<Bloque*> lista = dv->getListaBloques();
        Bloque * b = lista[pos];
        int size = strlen(data)/4096;

        if(size<1){
            b = new BloqueArchivo(nombre,pos,strlen(data));
            dv->getMasterBlock()->setSiguienteDisponible(pos+1);
            dv->getArchivo()->escribir(data,4096*pos,strlen(data));

            BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
            ba->setFileEntry(nombre,pos,pos,false,strlen(data),0,strlen(data)-1);
            dv->listaBloqueArchivo.push_back(ba);
            return ba;
        }
        else if(size>=1)
        {
            if(strlen(data)%4096>0)
                size++;
            b = new BloqueArchivo(nombre,pos,strlen(data));
            dv->getMasterBlock()->setSiguienteDisponible(pos+size);
            dv->getArchivo()->escribir(data,4096*pos,strlen(data));

            BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
            ba->setFileEntry(nombre,pos,pos+size-1,false,strlen(data),0,strlen(data)-1);
            dv->listaBloqueArchivo.push_back(ba);
            return ba;
        }
    }
    else if(tipo == "Folder")
    {
        FileEntry *fe = new FileEntry();
        int pos = dv->getMasterBlock()->getSigDisponible();
        vector<Bloque*> lista = dv->getListaBloques();
        Bloque * b = lista[pos];
        int size = strlen(data)/4096;

        if(size<1){

            b = new BloqueFolder(nombre,pos,strlen(data));
            dv->getMasterBlock()->setSiguienteDisponible(pos+1);
            dv->getArchivo()->escribir(data,4096*pos,strlen(data));

            BloqueFolder * bf = dynamic_cast<BloqueFolder*>(b);
            bf->setEspacioUtilizado(strlen(data)+1);
            bf->agregarFileEntry(fe,nombre,pos,pos,true,strlen(data),0,strlen(data)-1);
            dv->listaBloqueFolder.push_back(bf);
            bf->setNombre(nombre);
            return bf;
        }
        else if(size>=1)
        {
            if(strlen(data)%4096>0)
                size++;
            b = new BloqueFolder(nombre,pos,strlen(data));
            dv->getMasterBlock()->setSiguienteDisponible(pos+size);
            dv->getArchivo()->escribir(data,4096*pos,strlen(data));

            BloqueFolder * bf = dynamic_cast<BloqueFolder*>(b);
            bf->setEspacioUtilizado(strlen(data));
            bf->agregarFileEntry(fe,nombre,pos,pos+size-1,true,strlen(data),0,strlen(data)-1);
            dv->listaBloqueFolder.push_back(bf);
            bf->setNombre(nombre);
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

