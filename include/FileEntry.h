#ifndef FILEENTRY_H
#define FILEENTRY_H
#include <stdio.h>
#include <string.h>


class FileEntry
{
    public:
        FileEntry( char* nombre, int firstBlock, int lastBlock, int isFolder, int size );
        char* nombre;
        int firstBlock;
        int lastBlock;
        int isFolder;
        int size;

    protected:

    private:
};

#endif // FILEENTRY_H
