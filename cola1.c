#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};

int len;
int main(void) {




   struct my_msgbuf buf,buf2;
   int msqid ,msqid2;
   int toend;
   key_t key ,key2;
   system("touch msgq2.txt");


void* recibirsms(){
   while(1){
   if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1) {
         perror("msgrcv");
         exit(1);
      }
      printf("User1: %s\n", buf.mtext);
   }
}
void*  enviarsms(){
   while(1){
    fgets(buf2.mtext, sizeof(buf2.mtext), stdin);
       len = strlen(buf2.mtext);
      /* remove newline at end, if it exists */
      if (buf2.mtext[len-1] == '\n') buf2.mtext[len-1] = '\0';
      if (msgsnd(msqid2, &buf2, len+1, 0) == -1){
         perror("msgsnd");
         exit(1);
      }

   }
}
   
//------ esto para recibir lo mensaje ------
   if ((key = ftok("msgq.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
   if ((msqid = msgget(key, PERMS)) == -1) { /* connect to the queue */
      perror("msgget");
      exit(1);
   }
   printf("message queue: ready to receive messages.\n");
   
   //----acon este escribimos en la otroa cola-----
 if ((key2 = ftok("msgq2.txt", 'A')) == -1) {
      perror("ftok");
      exit(1);
   }
   //creamos la cola de mensajes
   if ((msqid2 = msgget(key2, PERMS | IPC_CREAT)) == -1) {
      perror("msgget");
      exit(1);
   }
   pthread_t id_hilo1;
   pthread_t id_hilo2;
   pthread_create(&id_hilo1,NULL,&recibirsms,NULL);
   pthread_create(&id_hilo2,NULL,&enviarsms,NULL);
   pthread_join(id_hilo2, NULL);
   pthread_join(id_hilo1, NULL);
   
   return 0;
}