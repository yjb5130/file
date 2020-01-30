#ifndef LY_FILE_H
#define LY_FILE_H

#include "ly_type.h"

extern S32 checkFileExist(CHAR* path);
extern S32 readAllHexFile(CHAR* path, UCHAR** buff);
extern S32 freeAllHexFileBuff(UCHAR* buff);

#endif //LY_FILE_H
