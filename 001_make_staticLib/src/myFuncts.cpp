#include "myFuncts.h"
#include "get_image.h"

bool initFuncts(char *_iniFile)
{
    if (ini_gets("RESOLUTION", "Width", "2592", buffIni, 8, iniFile))
    {
        IMAGE_WIDTH = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Width");
        return false;
    }

    if (ini_gets("RESOLUTION", "Height", "1944", buffIni, 8, iniFile))
    {
        IMAGE_HEIGHT = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Height");
        return false;
    }

    if (ini_gets("RESOLUTION", "Resize_Width", "2592", buffIni, 8, iniFile))
    {
        RESIZE_WIDTH = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Resize_Width");
        return false;
    }

    if (ini_gets("RESOLUTION", "Resize_Height", "1944", buffIni, 8, iniFile))
    {
        RESIZE_HEIGHT = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Resize_Height");
        return false;
    }

    switch(BIT_DEPTH)
    {  
        case 6:
        case 7:
        case 8:
            IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT;
            RESIZE_IMAGE_SIZE = RESIZE_WIDTH * RESIZE_HEIGHT;
            break;

        case 20:
            IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT * 4;
            RESIZE_IMAGE_SIZE = RESIZE_WIDTH * RESIZE_HEIGHT * 4;
            break;
        
        default:
            IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT * 2;
            RESIZE_IMAGE_SIZE = RESIZE_WIDTH * RESIZE_HEIGHT * 2;
            break;

    }
    /*
    printf("IMAGE_WIDTH= %d \r\n",IMAGE_WIDTH);
    printf("IMAGE_HEIGHT= %d \r\n",IMAGE_HEIGHT);
    printf("IMAGE_SIZE= %d \r\n",IMAGE_SIZE);
    printf("BufferType= %d \r\n",BufferType);
    */
    /*
    if (ini_gets("RESOLUTION", "Size", "10077696", buffIni, 10, iniFile))
    {
        IMAGE_SIZE = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Size");
        return false;
    }*/

    return true;
}
