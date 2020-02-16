#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "ly_type.h"

BOOL checkFileExist(CHAR* path)
{
    if (!access(path, F_OK))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

S32 readAllHexFile(CHAR* path, UCHAR** buff)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "rb");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }
    fseek(fd, 0, SEEK_END);
    s32Len = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    *buff = (UCHAR *) malloc(s32Len * sizeof(UCHAR));
    if (*buff == NULL)
    {
        fclose(fd);
        return -1;
    }
    fread(*buff, 1, s32Len, fd);
    fclose(fd);
    return s32Len;
}

S32 writeAllHexFile(CHAR* path, UCHAR* buff, S32 s32Length)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "wb");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }
    s32Len = fwrite(buff, 1, s32Length, fd);
    fclose(fd);
    return s32Len;
}

VOID freeAllHexFileBuff(UCHAR** buff)
{
    free(*buff);
    *buff = NULL;
}

S32 getHexFileLength(CHAR* path)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "rb");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }
    fseek(fd, 0, SEEK_END);
    s32Len = ftell(fd);
    fclose(fd);
    return s32Len;
}

S32 readHexFile(CHAR* path, UCHAR* buff, U32 length)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "rb");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }

    s32Len = fread(buff, 1, length, fd);
    fclose(fd);
    return s32Len;
}

S32 writeHexFile(CHAR* path, UCHAR* buff, U32 length)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "wb");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }

    s32Len = fwrite(buff, 1, length, fd);
    fclose(fd);
    return s32Len;
}

S32 readHexFileByte(CHAR* path, UCHAR* buff, U32 offset)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "rb");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }

    fseek(fd, offset, SEEK_SET);
    s32Len = fread(buff, 1, 1, fd);
    fclose(fd);
    return s32Len;
}

S32 writeHexFileByte(CHAR* path, UCHAR* buff, U32 offset)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "rb+");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }

    fseek(fd, offset, SEEK_SET);
    s32Len = fwrite(buff, 1, 1, fd);
    fclose(fd);
    return s32Len;
}

S32 readHexFileBytes(CHAR* path, UCHAR* buff, U32 offset, U32 length)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "rb");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }

    fseek(fd, offset, SEEK_SET);
    s32Len = fread(buff, 1, length, fd);
    fclose(fd);
    return s32Len;
}

S32 writeHexFileBytes(CHAR* path, UCHAR* buff, U32 offset, U32 length)
{
    FILE * fd = NULL;
    S32 s32Len = 0;
    fd = fopen(path, "rb+");
    if (!fd)
    {
        printf("open %s fail\n", path);
        return -1;
    }

    fseek(fd, offset, SEEK_SET);
    s32Len = fwrite(buff, 1, length, fd);
    fclose(fd);
    return s32Len;
}