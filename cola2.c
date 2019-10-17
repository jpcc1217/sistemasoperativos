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


int main(void) {

   struct my_msgbuf buf,buf2;
   int msqid,msqid2;
   int len;
   key_t key,key2;



void* recibirsms(){
   while(1){
   if (msgrcv(msqid2, &buf2, sizeof(buf2.mtext), 0, 0) == -1) {
         perror("msgrcv");
         exit(1);
      }
      printf("User1: %s\n", buf2.mtext);
   }
}
void*  enviarsms(){
   while(1){
    fgets(buf.mtext, sizeof(buf.mtext), stdin);
       len = strlen(buf.mtext);
      /* remove newline at end, if it exists */
      if (buf.mtext[len-1] == '\n') buf2.mtext[len-1] = '\0';
      if (msgsnd(msqid, &buf, len+1, 0) == -1){
         perror("msgsnd");
         exit(1);
      }

   }
}





   system("touch msgq.txt");//crea un archivo unico para general la llave 
//------ esto para recibir lo mensaje ------
   if ((key2 = ftok("msgq2.txt", 'A')) == -1) {//crea la llave 
      perror("ftok");
      exit(1);
   }
   if ((msqid2 = msgget(key2, PERMS)) == -1) { /* connect to the queue */
      perror("msgget");
      exit(1);
   }
   printf("message queue: ready to receive messages.\n");

   //------esto para envar mensajes-----------------------------
   if ((key = ftok("msgq.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
   //creamos la cola de mensajes
   if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1) {
      perror("msgget");
      exit(1);
   }
   printf(">\n");
   
   pthread_t id_hilo1;
   pthread_t id_hilo2;
   pthread_create(&id_hilo1,NULL,&recibirsms,NULL);
   pthread_create(&id_hilo2,NULL,&enviarsms,NULL);
   pthread_join(id_hilo2, NULL);
   pthread_join(id_hilo1, NULL);

   
   return 0;
}