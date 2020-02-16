#include <stdio.h>

#include "ly_type.h"

int main(void)
{
    S32 i = 0;
    BOOL s32Ret = FALSE;
    S32 s32Length = 0;
    S32 s32WriteLength = 0;
    S32 s32ReadLength = 0;
    UCHAR* pBuff;
    UCHAR buff[1024];
    UCHAR u1Data = 0;
    const CHAR* path = "test.bin";

    s32Ret = checkFileExist(path);
    if (s32Ret)
    {
        printf("%s is exist\n", path);
    }
    else
    {
        printf("%s is not exist\n", path);
    }

    s32Length = readAllHexFile(path, &pBuff);
    if (s32Length > 0)
    {
        printf("readAllHexFile length: %d\n", s32Length);
        printf("readAllHexFile pBuff:");
        for (i = 0; i < s32Length; i++)
        {
            if (i % 0x10 == 0)
            {
                printf("\n");
            }
            printf("0x%02x, ", pBuff[i]);
        }
        printf("\n");
        s32WriteLength = writeAllHexFile("test2.bin", pBuff, s32Length);
        printf("writeAllHexFile length: %d\n", s32WriteLength);
        freeAllHexFileBuff(&pBuff);
    }
    else
    {
        printf("readAllHexFile fail: %s\n", path);
    }

    s32Length = getHexFileLength(path);
    printf("getHexFileLength: %d\n", s32Length);

    s32ReadLength = readHexFile(path, buff, s32Length);
    printf("readHexFile s32ReadLength: %d\n", s32ReadLength);
    if (s32ReadLength > 0)
    {
        printf("readHexFile buff:");
        for (i = 0; i < s32ReadLength; i++)
        {
            if (i % 0x10 == 0)
            {
                printf("\n");
            }
            printf("0x%02x, ", buff[i]);
        }
        printf("\n");
        s32WriteLength = writeHexFile("test3.bin", buff, s32Length);
        printf("writeHexFile length: %d\n", s32WriteLength);
    }

    u1Data = 0xfc;
    s32WriteLength = writeHexFileByte(path, &u1Data, 0x80);
    if (s32WriteLength > 0)
    {
        s32ReadLength = readHexFileByte(path, &u1Data, 0x80);
        if (s32ReadLength > 0)
        {
            printf("readHexFileByte u1Data: 0x%x\n", u1Data);
        }
        else
        {
            printf("readHexFileByte error!");
        }
    }
    else
    {
        printf("writeHexFileByte error!");
    }
    return 0;
}
