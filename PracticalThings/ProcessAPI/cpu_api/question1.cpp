#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int x = 100;
    int rc = fork();
    if(rc < 0){
        printf("fork failed");
        exit(1);
    }else if(rc == 0){
        x = 99;
        printf("x value: %d\n", x);
    }else{
        x = 102;
        printf("parent process x value: %d\n", x);
    }
    return 0;
}