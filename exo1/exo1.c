#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>


int main(){
    int p_des[2];
    char buff[255];
    
    if(pipe(p_des)!=0){
        printf("erreur lors de la création du pipe");
        exit(errno);
    }
    
    if(fork()){
        close(p_des[0]);
        while(1){
            printf("Veuillez saisir votre message\n");
            fgets(buff,sizeof(buff),stdin);
            write(p_des[1],buff,sizeof(buff));
            sleep(1);
        }
    }else{
        close(p_des[1]);
        while(1){
            if(read(p_des[0],buff,sizeof(buff))){
                printf("msg >> %s\n",buff);
            }
        }
    }
    
    return 0;
}

