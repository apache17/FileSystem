#include "FileEntry.h"

FileEntry::FileEntry(char *nombre, int firstBlock, int lastBlock, int isFolder, int size) {
    strcpy(this->nombre, nombre);
    this->firstBlock = firstBlock;
    this->lastBlock = lastBlock;
    this->isFolder = isFolder;
    this->size = size;
}
