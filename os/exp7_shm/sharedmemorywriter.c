// IPC with shared memory segment (writer)
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
 
int main() {
    key_t key = ftok("randomstr",25);
 
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    char *str = (char*) shmat(shmid,(void*)0,0);
	
	while(strcmp(str,"Stop")!=0) {
 
        printf("Write Data : ");
        fgets(str,80,stdin);
        sleep(10);
        printf("Program 2 msg: %s\n",str);
    }    
    
    shmdt(str);
 
    return 0;
}
