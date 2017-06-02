#include "api.h"

API::API()
{
    rootSize = 0;
}

void API::abrirFolder(char * nombre)
{
   // vector<BloqueFolder*> lista = dv->listaBloqueFolder;

   for(int x = 0;x<dv->listaBloqueFolder.size();x++)
    {
        if(dv->listaBloqueFolder.at(x)->getNombre() == nombre)
        {
            dv->setFolderActual(dv->listaBloqueFolder.at(x));
            cout<<"Folder abierto correctamente"<<endl;
        }
    }
}

void API::crearDiscoVirtual()
{
    char * c = {"Disco Virtual"};
    Archivo * archivo = new Archivo(c,1048576);
    dv = new DiscoVirtual(archivo,1048576,4096);
    dv->formatear();
    addRoot();
    dv->setFolderActual(root);
}

void API::addRoot(){
    int pos = 1;
    char * ra = {"Raiz"};
    vector<Bloque*> lista = dv->getListaBloques();
    Bloque * bloque = lista[0];
    bloque = new BloqueFolder(ra,1,0,dv->getArchivo());
    BloqueFolder * nRoot = dynamic_cast<BloqueFolder*>(bloque);
    dv->getMasterBlock()->setSiguienteDisponible(pos+3);
    dv->listaBloqueFolder.push_back(nRoot);
    nRoot->setNombre(ra);
    this->root = nRoot;
}

Bloque * API::crearArchivo(char * nombre, BloqueFolder * actual, char * contenido)
{
    Archivo * archivo = dv->getArchivo();
    archivo->abrir();
    int pos = dv->getMasterBlock()->getSigDisponible();
    vector<Bloque*> lista = dv->getListaBloques();
    Bloque * b = lista[pos-1];

    b = new BloqueArchivo(nombre,pos,strlen(contenido),dv->getArchivo());
    actual->getFileEntry()->setSize(strlen(contenido));

    BloqueArchivo * ba = dynamic_cast<BloqueArchivo*>(b);
    int size = strlen(contenido)/4096;

    if(size<1)
    {
        dv->getMasterBlock()->setSiguienteDisponible(pos+1);
        archivo->escribir(contenido,pos*4096,strlen(contenido));
        ba->setFileEntry(nombre,pos,pos,false,strlen(contenido));
        actual->agregarFileEntry(ba->getFileEntry());

    }

    else if(size>=1)
    {
        if(strlen(contenido)%4096>0)
            size++;
        dv->getMasterBlock()->setSiguienteDisponible(pos+size);
        archivo->escribir(contenido,pos*4096,strlen(contenido));
        ba->setFileEntry(nombre,pos,pos+size,false,strlen(contenido));
        actual->agregarFileEntry(ba->getFileEntry());
    }

    dv->listaBloqueArchivo.push_back(ba);
    escribirEntries(ba->getFileEntry());
    return ba;
}

Bloque * API::crearFolder(char * nombre,BloqueFolder * actual)
{
    Archivo * archivo = dv->getArchivo();
    archivo->abrir();
    int pos = dv->getMasterBlock()->getSigDisponible();
    vector<Bloque*> lista = dv->getListaBloques();
    Bloque * b = lista[pos-1];

    b = new BloqueFolder(nombre,pos,0,archivo);
    dv->getMasterBlock()->setSiguienteDisponible(pos+1);
    BloqueFolder * bf = dynamic_cast<BloqueFolder*>(b);


    bf->setFileEntry(nombre,pos,pos,true,0);
    actual->agregarFileEntry(bf->getFileEntry());
    escribirEntries(bf->getFileEntry());
    bf->setNombre(nombre);
    dv->listaBloqueFolder.push_back(bf);

    return bf;
}

void API::escribirEntries(FileEntry *fe)
{
    char * data = new char[48];
    int firstBlock = fe->getFirstBLock();
    int lastBlock = fe->getLastBlock();
    int size = fe->getSize();
    int esFolder = fe->getEsFolder();
    int pos = 0;

    memcpy(&data[pos], fe->getNombre(), 35);
    pos+=35;
    memcpy(&data[pos], &firstBlock,4);
    pos+=4;
    memcpy(&data[pos], &lastBlock, 4);
    pos+=4;
    memcpy(&data[pos], &esFolder, 1);
    pos+=1;
    memcpy(&data[pos], &size, 4);
    pos+=4;

    dv->getArchivo()->abrir();
    dv->getArchivo()->escribir(data,4096+rootSize,48);
    rootSize += 48;
}

void API::dir()
{
    vector<BloqueFolder*> lista = dv->listaBloqueFolder;
    for(int x = 0; x < lista.size();x++)
    {
        vector<FileEntry*> listaE = lista[x]->getListaEntries();
        cout<<"Folder: ";
        lista[x]->imprimirNombre();
        cout<<""<<endl;
        for(int y = 0; y < listaE.size();y++)
        {
             listaE[y]->imprimirEntry();
             cout<<""<<endl;
        }
        cout<<"-------------------------"<<endl;
        cout<<""<<endl;
    }
}

void API::dirFolderActual()
{
        cout<<""<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"Folder Actual: ";
        dv->getFolderActual()->imprimirNombre();
        cout<<"Contenido del Folder: ";
        vector<FileEntry*> lista = dv->getFolderActual()->getListaEntries();
        for(int y = 0; y < lista.size();y++)
        {
             lista[y]->imprimirEntry();
             cout<<""<<endl;
        }
        cout<<"-------------------------"<<endl;
}

