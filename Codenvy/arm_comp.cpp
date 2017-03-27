#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const char STR_EXEC[25] = "arm-linux-gnueabihf-g++ ";

int main(int argv, char *argc[])
{
    int len = 0, i = 0;
    char filename[32];
    char exec[128];
    char buf[128];
    char file[32];
    
    
    len = strlen(argc[1]);
    cout << "sizeof(argc[1]) = " << len << endl;
    
    for(i = len;i>=0;i--)
    {//find the file
        if(argc[1][i] == '/')
            break;
    }
    
    //if '/' is not found then assume entry is the filename
    //Also check that final 3 chars are .cpp
    
    strncpy(filename,&argc[1][i+1],31);
    strncpy(file,filename,31);
//debug    cout << "Filename is " << filename << endl;
    
    //find lenght of name plus file type
    len = strlen(file);
    
    for(i=len;i>=0;i--)
    {//replace '.' with NULL
        if(file[i] == '.')
        {
            file[i] = '\0';
        }
    }
    
    cout << "file = " << file << endl;
    
    //copy executable name into file
    strncpy(exec,STR_EXEC,64);
    strncat(exec,filename,127);
    sprintf(buf," -o %s",file);
    strncat(exec,buf,127);
//debug    cout << exec << endl;
    
    //TODO system run of arm-linux-gnueabihf-g++ for .o file
    //TODO system run for creating executable
    
    system(exec);
    
    return 0;
}