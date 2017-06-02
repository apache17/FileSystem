#include <iostream>
#include "api.h"
using namespace std;
#include "DiscoVirtual.h"
#include "MasterBlock.h"
#include "Archivo.h"
#include "masterblock.h"

int main()
{
    API * api = new API();

    int opcion;
    int opcion2;
    do{
        cout<<"1- Crear Disco Virtual"<<endl;
        cout<<"2- Salir"<<endl;
        cout<<"Elija una opcion: ";
        cin>>opcion;
        cout<<""<<endl;
    }while(opcion != 1 && opcion !=2);

    if(opcion == 1)
    {
        api->crearDiscoVirtual();
        cout<<"Disco Virtual Creado!"<<endl;
        do
        {
            cout<<""<<endl;
            cout<<"1- Crear un Archivo"<<endl;
            cout<<"2- Crear un Folder"<<endl;
            cout<<"3- Listar Archivos de la carpeta actual"<<endl;
            cout<<"4- Listar todos los Archivos"<<endl;
            cout<<"5- Abrir un Folder"<<endl;
            cout<<"6- Salir"<<endl;
            cout<<"Elija una opcion: ";
            cin>>opcion2;

            if(opcion2 == 1)
            {
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
                cout<<"Ingrese el nombre del Folder: ";
                string nombre;
                cin>>nombre;
                char * nombreChar = new char[nombre.length()+1];
                memcpy(&nombreChar[0], nombre.c_str(),nombre.length());
                api->crearFolder(nombreChar,api->dv->getFolderActual());
            }

            else if(opcion2 == 3)
            {
                api->dirFolderActual();
            }

            else if(opcion2 == 4)
            {
                api->dir();
            }

            else if(opcion2 == 5)
            {
                cout<<"Ingrese el nombre del Folder: ";
                string nombre;
                cin>>nombre;
                char * nombreChar = new char[nombre.length()+1];
                memcpy(&nombreChar[0], nombre.c_str(),nombre.length());
                api->abrirFolder(nombreChar);
            }

        }while(opcion2 !=6);
    }
}
