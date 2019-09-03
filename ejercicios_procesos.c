#include <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>
#include <unistd.h>

//-------------- semana 7 ejercicio 1 --------------------------//

/*int main(int argc, char *argv[]) {

 printf("argc =  %d\n",argc);
 for(int i = 0; i< argc; i++){
 printf("argv[%d] = %s\n", i,argv[i]);
 }


 }*/

//-------------- semana 7 ejercicio 2 --------------------------//
/*int main(int argc, char *argv[]) {


 float promedio = 0;

 int min = strtof(argv[1], NULL);
 int max = strtof(argv[1], NULL);

 for (int i = 1; i < argc; i++) {
 int temp = strtof(argv[i], NULL);
 promedio += temp;
 if (temp < min) {
 min = temp;
 }

 if (temp > max) {
 max = temp;
 }
 }

 printf("promedio %f = \n", promedio / (argc - 1));
 printf("minimo %d = \n", min);
 printf("maximo %d = \n", max);

 }*/

/*int main(int argc, char **argv) {

 printf("argc =  %d\n",argc);
 for(int i = 0; i< argc; i++){
 printf("argv[%d] = %s\n", i, *(argv + i));
 }

 }*/

//-------------- semana 7 ejercicio 4 --------------------------//
float factorial(int n, int m) {
	float temp;
	for (int i = n; i < m; i++) {

		for (int j = 1; j < n; j++) {

			temp = temp * j;

		}
		printf("el factorial %d es %f\n", i, temp);
	}

	return temp;
}

int main(int argc, char *argv[]) {

	pid_t pid1, pid2;
#include <unistd.h>
	pid1 = fork();
	if (pid1 == 0) {
		factorial(1, 10);
	} else {
		pid2 = fork();
		if (pid2 == 0) {
			factorial(1, 10);
		} else {
			factorial(1, 10);
		}
	}

	/*
	 pid1 = fork();
	 if (pid1 == 0) {
	 factorial(1, 10);
	 }
	 pid2 = fork();
	 if (pid2 == 0) {
	 factorial(1, 10);
	 }

	 pid3 = fork();
	 if (pid3 == 0) {
	 factorial(1, 10);
	 }*/

}

/*int main(int argc, char *argv[]) {
 //-------------- semana 7 ejercicio 5 --------------------------//
 printf("argc =  %d\n",argc);
 for(int i = 0; i< argc; i++){
 printf("argv[%d] = %s\n", i,argv[i]);
 }
 exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error


 }*/

/*int main(int argc, char *argv[]) {
 //-------------- semana 7 ejercicio 6 --------------------------//
 printf("argc =  %d\n",argc);
 for(int i = 0; i< argc; i++){
 printf("argv[%d] = %s\n", i,argv[i]);
 }
 exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error


 }*/
