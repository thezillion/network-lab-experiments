// Parent and child process using fork()
#include<stdio.h>
#include<unistd.h>

int main() {
    int id;
    id = fork();
    
    if(id > 0) {
        printf("This is the parent section [Process id: %d]\n",getpid());
    } else if(id == 0) {
        printf("Fork created. [Process id: %d]\n", getpid());
        printf("Fork parent process id. [Process id: %d]\n",getppid());
    } else {
        printf("Fork creation failed\n");
    }

    return 0;
}
