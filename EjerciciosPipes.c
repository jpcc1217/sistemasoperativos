#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BuffSize 20

int main(int argc, char *argv[]) {

	int pipeDescriptors1[2];
	int pipeDescriptors2[2];

	char buffer[BuffSize];

	char* msg;

	if (pipe(pipeDescriptors1) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	if (pipe(pipeDescriptors2) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	switch (fork()) {

	case -1:
		perror("pipe");
		exit(EXIT_FAILURE);
	case 0: //hijo
		msg = "hola";
		write(pipeDescriptors2[1], msg, BuffSize);
		read(pipeDescriptors1[0], buffer, BuffSize);
		printf("el hijo escribe: %s y lee: %s ",msg,buffer);
		exit(EXIT_SUCCESS);

	default: //padre
		msg = "mundo";
		write(pipeDescriptors1[0], msg, BuffSize);
		read(pipeDescriptors2[1], buffer, BuffSize);
		printf("el padre escribe: %s y lee: %s ",msg,buffer);
		exit(EXIT_SUCCESS);

	}

}
