/*
 * Juan Pablo Cano Cuadros
 * 000156364
 *
 * */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMISOS 0644
struct msgBuffer {
	long msgType;
	char msgText[100];
};

int len;
int main(void) {

	pthread_t id_hilo1;
	pthread_t id_hilo2;

	struct msgBuffer msgBuffer1, msgBuffer2;
	int queueId1, queueId2;
	key_t key1, key2;

	void* getMsg() {
		while (1) {
			if (msgrcv(queueId1, &msgBuffer1, sizeof(msgBuffer1.msgText), 0, 0)
					== -1) {
				perror("error en msgrcv");
				exit(1);
			}
			printf("Usuario 1: %s\n", msgBuffer1.msgText);
		}
	}
	void* sendMsg() {
		while (1) {
			fgets(msgBuffer2.msgText, sizeof(msgBuffer2.msgText), stdin);
			len = strlen(msgBuffer2.msgText);
			/* remove newline at end, if it exists */
			if (msgBuffer2.msgText[len - 1] == '\n')
				msgBuffer2.msgText[len - 1] = '\0';
			if (msgsnd(queueId2, &msgBuffer2, len + 1, 0) == -1) {
				perror("error en msgsnd");
				exit(1);
			}

		}
	}

    // Recibir mensajes
	if ((key1 = ftok("/home/ub/Escritorio/pruebaParcial3/msg1.text", 'Y'))
			== -1) {
		perror("error en ftok");
		exit(1);
	}
	if ((queueId1 = msgget(key1, PERMISOS | IPC_CREAT)) == -1) {
		perror("error en msgget");
		exit(1);
	}
	printf("Envia un mensaje.\n");

	//Enviar mensajes
	if ((key2 = ftok("/home/ub/Escritorio/pruebaParcial3/msg2.text", 'X'))
			== -1) {
		perror("error en ftok");
		exit(1);
	}
	//Cola de mensajes
	if ((queueId2 = msgget(key2, PERMISOS | IPC_CREAT)) == -1) {
		perror("error en msgget");
		exit(1);
	}

	pthread_create(&id_hilo1, NULL, &getMsg, NULL);
	pthread_create(&id_hilo2, NULL, &sendMsg, NULL);
	pthread_join(id_hilo2, NULL);
	pthread_join(id_hilo1, NULL);

}
