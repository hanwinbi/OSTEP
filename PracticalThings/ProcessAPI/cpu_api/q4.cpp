#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *args[]){
    int rc = fork();
    if(rc < 0){
        printf("fork failed");
        exit(1);
    }else if(rc == 0){
        const char *myarg[3];
        myarg[0] = "/bin/ls";
        myarg[1] = "./";
        myarg[2] = NULL;
        execl(myarg[0], myarg[1], myarg[2]);
    }else{
        printf("parent process\n");
    }
    return 0;
}