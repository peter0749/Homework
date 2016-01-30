#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LEN 512

int main(void)
{
    int fno1, fno2, readbytes;
    int buff[LEN];
    char f1path[LEN], f2path[LEN];
    printf("Source: ");
    gets(f1path);
    printf("Target: ");
    gets(f2path);

    fno1 = open(f1path,O_RDONLY);
    fno2 = open(f2path,O_CREAT|O_WRONLY,S_IWRITE|S_IREAD);
    if(fno1==-1 || fno2==-1)
    {
        printf("Failed...\n");
        return -1;
    }
    while(eof(fno1)==0)
    {
        readbytes = read(fno1,buff,LEN);
        write(fno2,buff,readbytes);
    }
    close(fno1);
    close(fno2);
    printf("Successfully copied from %s to %s\n",f1path,f2path);
    return 0;
}
