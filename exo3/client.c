#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>


int main(){
    int fd;
    char firstname[100],lastname[100],buff[100];
    
    mkfifo("/tmp/pipe1",S_IRWXU|S_IRGRP);
    
    fd=open("/tmp/pipe1",O_WRONLY);
    
    printf("Veuillez saisir un prénom\n");
    fgets(firstname,sizeof(firstname),stdin);
    printf("Veuillez saisir un nom\n");
    fgets(lastname,sizeof(lastname),stdin);
    strcpy(buff,strcat(firstname,lastname));
    write(fd,buff,sizeof(buff));
    close(fd);
    

    return 0;
}

