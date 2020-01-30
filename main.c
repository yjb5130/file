#include <stdio.h>

#include "ly_type.h"

int main(void)
{
    S32 s32Ret;
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
    
    return 0;
}