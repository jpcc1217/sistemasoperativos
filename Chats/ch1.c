#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/mman.h>
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

void* transmitThread(void * pdata){
    
	int mapTx_fd = shm_open("mapTx", O_CREAT | O_RDWR, 0666); 
    ftruncate(mapTx_fd, 4096); 
	void* mapTx_ptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, mapTx_fd, 0);
    sem_t *semTx = sem_open("semTx",O_CREAT | O_RDWR, 0666, 0);

    char * status;
    int semTxValue;
    
    printf("Init client 1 Tx\n");

    while(1){
        sem_getvalue(semTx,&semTxValue);
        if(semTxValue == 0){
            status = fgets( (char *) mapTx_ptr, 4096, stdin);   
            if( status == NULL){
                break;
            }
            sem_post(semTx);
        }
    }
    pthread_exit(NULL);
}

int main() 
{ 
	pthread_t idTx;

	int mapRx_fd = shm_open("mapRx", O_CREAT | O_RDWR, 0666); 
    ftruncate(mapRx_fd, 4096); 
	void* mapRx_ptr = mmap(0, 4096, PROT_READ, MAP_SHARED, mapRx_fd, 0);
    pthread_create(&idTx,NULL,transmitThread,NULL);
    sem_t *semRx = sem_open("semRx",O_CREAT | O_RDWR, 0666, 0);
    int semRxValue;

    printf("Init client 1 Rx\n");
    while(1){
        sem_getvalue(semRx,&semRxValue);
        if(semRxValue == 1){
            printf("Receive message: %s",(char *)mapRx_ptr);
            sem_wait(semRx);
        }    
    }
    pthread_join(idTx,NULL);
    shm_unlink("mapRx");
	return 0; 
} 
