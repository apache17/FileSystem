#ifndef FILEENTRY_H
#define FILEENTRY_H
#include <stdio.h>
#include <string.h>


class FileEntry
{
    public:
        FileEntry( char* nombre, int firstBlock, int lastBlock, int isFolder, long size );
        char* nombre;
        int firstBlock;
        int lastBlock;
        int isFolder;
        long size;

    protected:

    private:
};

#endif // FILEENTRY_H
