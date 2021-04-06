#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *args[]){
    int rc = fork();
    if(rc < 0){
        printf("fork failed");
        exit(1);
    }else if(rc == 0){
        char *arg[3];
        arg[0] = strdup("printf");
        arg[1] = strdup("hello\n");
        arg[2] = NULL;
        execvp(arg[0], arg);
    }else{
        wait(NULL);
        printf("goodbye\n");
    }
    return 0;
}