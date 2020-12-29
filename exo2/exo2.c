#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <string.h>

int main(){
    int p_des[2];
    char buff[255];
    FILE * file;
    
    if(pipe(p_des)!=0){
        printf("erreur lors de la création du pipe");
        exit(errno);
    }
    
    if(fork()){
        close(p_des[0]);
        while(1){
            printf("Veuillez saisir votre message\n");
            fgets(buff,sizeof(buff),stdin);
            if(strncmp(buff,"exit()",6)==0){
                write(p_des[1],buff,sizeof(buff));
                break;
                //return 1;
            }
            write(p_des[1],buff,sizeof(buff));
            sleep(1);
        }
    }else{
        close(p_des[1]);
        while(1){
            if(read(p_des[0],buff,sizeof(buff))){
                if(strncmp(buff,"exit()",6)==0){
                    printf("Fin du programme\n");
                    write(p_des[1],buff,sizeof(buff));
                    break;
                }else{
                printf("msg >> %s\n",buff);
                file=fopen("output.txt","w");
                if(file != NULL) {
                        fputs(buff,file);
                        fclose(file);
                }else{
                    printf("Erreur lors de la création du fichier");
                }
                
                }
            }
        }
        exit(0);
    }
    
    return 0;
}

