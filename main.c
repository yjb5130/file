#include <stdio.h>

#include "ly_type.h"

int main(void)
{
    S32 i;
    S32 s32Ret;
    S32 s32Length;
    S32 s32WriteLength;
    UCHAR* buff;
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

    s32Length = readAllHexFile(path, &buff);
    if (s32Length > 0)
    {
        printf("readAllHexFile length: %d\n", s32Length);
        printf("readAllHexFile buff:");
        for (i = 0; i < s32Length; i++)
        {
            if (i % 0x10 == 0)
            {
                printf("\n");
            }
            printf("0x%02x, ", buff[i]);
        }
        printf("\n");
        s32WriteLength = writeAllHexFile("test2.bin", buff, s32Length);
        printf("writeAllHexFile length: %d\n", s32WriteLength);
        freeAllHexFileBuff(&buff);
    }
    else
    {
        printf("readAllHexFile fail: %s\n", path);
    }
    return 0;
}
