// Program to output process id, parent process id, group id, user id
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main() {
    printf("pid is %d\n", getpid());
    printf("Parent pid is %d\n", getppid());
    printf("Group pid is %d\n", getgid());
    printf("User id is %d\n", getuid());
}