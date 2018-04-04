// IPC using pipes
#include<stdio.h>
#include<unistd.h>
#include<string.h>

void main() {

    int fd[2],n;
    char readbuffer[80];
    char string[] = "Hello World\n";
    pid_t childpid;
    pipe(fd);

    if((childpid = fork()) == -1) {
        printf("Fork process creation failed\n");
    } else if(childpid == 0) {
        close(fd[0]);
        write(fd[1], string, strlen(string) + 1);
        printf("Sent string is %s\n", string);
        exit(0);
    } else {
        close(fd[1]);
        n = read(fd[0], readbuffer, sizeof(readbuffer));
        printf("Recieved string is %s", readbuffer);
    }

    return 0;

}

