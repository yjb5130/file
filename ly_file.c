#include <stdio.h>
#include <unistd.h>

#include "ly_type.h"

S32 checkFileExist(CHAR* path)
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
