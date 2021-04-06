#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
    printf("parent process to read file\n");
    char *out = (char *)malloc(sizeof(char));
    int file;
    int fd = open("./test.txt", O_RDWR);
    int rc = fork();
    if(rc < 0){
        printf("open file failed");
        exit(1);
    }else if (rc == 0) // child access
    {
        if(fd > 0){
            // read file
            // printf("child can access fd");
            // file = read(fd, out, 22);
            // out[file] = '\0';
            // printf("this is child access file content: %s \n", out);
            // write file
            file = write(fd, "hello child world\n", strlen("hello child world\n"));
            close(fd);
        }
    }else{
        //read file
        // file = read(fd, out, 22);
        // out[file] = '\0';
        // printf("this is file content: %s \n", out);
        // write file
        file = write(fd, "hello parent world\n", strlen("hello child world\n"));
        close(fd);
    }
    
    return 0;
}