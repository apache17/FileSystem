#include <iostream>
#include "api.h"
using namespace std;
#include "Archivo.h"


int main()
{
    /*char * nombre = {"DiscoVirtual.txt"};
    char * nombre2 = {"Mierqwereaaaaaaaaaaaaaaaaaa"};
    Archivo * arch = new Archivo(nombre,256*4096);
    arch->escribir(nombre2,20*4096,strlen(nombre2));
    char * a = arch->leer(4096*20,strlen(nombre2));
    for(int x =0; x<strlen(a);x++)
        cout<<a[x];*/

    API * api = new API();

    int opcion2;
    api->crearDiscoVirtual();
    api->initFromChar();

    do
    {
        cout<<""<<endl;
        cout<<"1- Crear un Archivo"<<endl;
        cout<<"2- Crear un Folder"<<endl;
        cout<<"3- Leer un Archivo"<<endl;
        cout<<"4- Listar Archivos de la carpeta actual"<<endl;
        cout<<"5- Listar todos los Archivos"<<endl;
        cout<<"6- Abrir un Folder"<<endl;
        cout<<"7- Salir"<<endl;
        cout<<"Elija una opcion: ";
        cin>>opcion2;

        if(opcion2 == 1)
        {
            cout<<""<<endl;
            cout<<"Ingrese el nombre del Archivo: ";
            string nombre;
            cin>>nombre;
            char * nombreChar = new char[nombre.length()+1];
            strcpy(nombreChar, nombre.c_str());

            cout<<"Ingrese el contenido: ";
            string contenido;
            cin>>contenido;
            char * contenidoChar = new char[contenido.length()];
            strcpy(contenidoChar, contenido.c_str());

            api->crearArchivo(nombreChar,api->dv->getFolderActual(),contenidoChar);
        }
        else if(opcion2 == 2)
        {
            cout<<""<<endl;
            cout<<"Ingrese el nombre del Folder: ";
            string nombre;
            cin>>nombre;
            char * nombreChar = new char[nombre.length()+1];
            strcpy(nombreChar, nombre.c_str());
            api->crearFolder(nombreChar,api->dv->getFolderActual(),5);
        }

        else if(opcion2 == 3)
        {
            cout<<""<<endl;
            cout<<"Ingrese el nombre del Archivo: ";
            string nombre;
            cin>>nombre;
            char * nombreChar = new char[nombre.length()+1];
            memcpy(&nombreChar[0], nombre.c_str(),nombre.length());
            int x = api->leerArchivo(nombreChar,api->dv->getFolderActual());
        }

        else if(opcion2 == 4)
        {
            cout<<""<<endl;
            api->dirFolderActual();
        }

        else if(opcion2 == 5)
        {
            cout<<""<<endl;
            api->dir();
        }

        else if(opcion2 == 6)
        {
            cout<<""<<endl;
            cout<<"Ingrese el nombre del Folder: ";
            string nombre;
            cin>>nombre;
            char * nombreChar = new char[nombre.length()+1];
            memcpy(&nombreChar[0], nombre.c_str(),nombre.length());
            api->abrirFolder(nombreChar);
        }



    }while(opcion2 !=7);
}
