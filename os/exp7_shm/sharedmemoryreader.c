// IPC with shared memory segment (reader)
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
 
int main() {
    key_t key = ftok("randomstr",25);
 
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
 
    char *str = (char*) shmat(shmid,(void*)0,0);
	while(1){
        printf("Program 1 msg: %s\n",str);
        printf("Write reply:");
        fgets(str, 80, stdin);
        sleep(20);
    }
     
    shmdt(str);
   
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}
