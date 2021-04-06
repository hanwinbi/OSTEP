#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();  // 父进程和子进程返回值不一样，子进程是父进程的copy但\\
    运行到这一步的时候返回值为0
    if(rc < 0){
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        // chile (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    }else{
        // parent goes down
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    }
    return 0;
}