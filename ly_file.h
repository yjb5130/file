#ifndef LY_FILE_H
#define LY_FILE_H

#include "ly_type.h"

extern BOOL checkFileExist(CHAR* path);
extern S32 readAllHexFile(CHAR* path, UCHAR** buff);
extern S32 writeAllHexFile(CHAR* path, UCHAR* buff);
extern VOID freeAllHexFileBuff(UCHAR* buff);

extern S32 getHexFileLength(CHAR* path);
extern S32 readHexFile(CHAR* path, UCHAR* buff, U32 length);
extern S32 writeHexFile(CHAR* path, UCHAR* buff, U32 length);

extern S32 readHexFileByte(CHAR* path, UCHAR* buff, U32 offset);
extern S32 writeHexFileByte(CHAR* path, UCHAR* buff, U32 offset);
#endif //LY_FILE_H
