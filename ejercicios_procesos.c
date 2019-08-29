#include <stdio.h>
#include <stdlib.h>

/*int main(int argc, char *argv[]) {
 //-------------- semana 7 ejercicio 1 --------------------------//
 printf("argc =  %d\n",argc);
 for(int i = 0; i< argc; i++){
 printf("argv[%d] = %s\n", i,argv[i]);
 }


 }*/

int main(int argc, char *argv[]) {

	//-------------- semana 7 ejercicio 2 --------------------------//
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

}

/*int main(int argc, char *argv[]) {
 //-------------- semana 7 ejercicio 3 --------------------------//
 printf("argc =  %d\n",argc);
 for(int i = 0; i< argc; i++){
 printf("argv[%d] = %s\n", i,argv[i]);
 }
 exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error


 }*/

/*int main(int argc, char *argv[]) {
 //-------------- semana 7 ejercicio 4 --------------------------//
 printf("argc =  %d\n",argc);
 for(int i = 0; i< argc; i++){
 printf("argv[%d] = %s\n", i,argv[i]);
 }
 exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error


 }*/

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
