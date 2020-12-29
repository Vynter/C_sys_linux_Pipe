#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd;
    char buff[100];
    
    mkfifo("/tmp/pipe1",S_IRWXU|S_IRGRP);
    
    fd=open("/tmp/pipe1",O_RDONLY);
    read(fd,buff,sizeof(buff));
    printf("le nom complet est : %s",buff);
    close(fd);
    

    return 0;
}

