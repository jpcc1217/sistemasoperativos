/*
 ============================================================================
 Name        : semana.c
 Author      : juan diego valencia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // for wait()
#include <unistd.h>
//ejericio 2
/*
 int main(int argc, char *argv[]) {
     int arreglo[argc];
     int promedrio;
     int suma=0;
     printf("argc =  %d\n",argc);
     for(int i = 1; i< argc; i++){
         sscanf(argv[i],"%d",&arreglo[i]);//sscanf escanea charts que son numeros y los parsea sirectamente
         printf("arreglo[%d] = %d\n", i,arreglo[i]);
         suma=suma+arreglo[i];
     }
     int mayor = arreglo[1]; //Le asignamos el primer elemento del array
     int menor = arreglo[1]; //Así empezamos a comparar
     promedrio=suma/(argc-1);
 for (int i=1; i<argc; i++){
    if (arreglo[i]> mayor){
    mayor=arreglo[i];
    }
    if (arreglo[i]< menor){
    menor=arreglo[i];
    }
 }
 printf("el mayor es %d \n el menor es %d  el promedio es %d",mayor,menor,promedrio);


     exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
 }
*/

//EJerciio 3
/*
 int main(int argc, char **argv) {

     printf("argc =  %d\n",argc);
     for(int i = 0; i< argc; i++){
         printf("argv[%d] = %s\n", i, argv[i]);
     }
     exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
 }
*/
//ejerciico 4 imprimer en horden desentende primero el ultimo hijo hasta el padre

//ejercicio4
/*
int main() {
	int child=0;
	pid_t id1=fork();
	pid_t id2=fork();

    // parent process
    if (id1 > 0 && id2 > 0) {

        wait(NULL);
        wait(NULL);
      //printf("Parent Terminated\n");
    }
    //firts child
    else if (id1 == 0 && id2 > 0) {
    		child=1;
    		 kill(id2, SIGKILL);
        // sleep the process for 2 seconds
        // to ensure 2nd child executes first
    	//sleep(2);
       //wait(NULL);
        //printf( "1st child Terminated\n");

    }

    // second child
    else if (id1 > 0 && id2 == 0) {
    	child=2;
        // sleep the process for 1 second
        //sleep(1);
       // printf("2nd Child Terminated\n" );

    }

    // grand child
    else {
    	child=3;
    	//printf("Grand Child Terminated\n" );
    }
		int factorial=1;
		for(int j=1;j<=10;j++){
			factorial=1;
			for(int i=1;i<=j;i++){
				factorial=factorial*i;
			}
			printf("HIJO%d: fact(%d) = %d \n",child,j,factorial);

		}

return 0;

}

*/


 //ejercicio5

int main(int argc, char *argv[]) {
	//int child=0;
	pid_t id2;
	pid_t id3;
	pid_t id1=fork();
		id2=fork();
		id3=fork();
	if(id1>0&&id2>0&&id3>0){
		wait(NULL);
		wait(NULL);
		wait(NULL);
		printf("ejectandose papa\n");
	}
	else if(id1==0&&id2>0&&id3>0){
		printf("ejectandose hijo 1\n");
		char *args[]={"/home/juan/Documentos/promedio/src/./promedio",NULL};
				         execv(args[0],argv);
				         /*All statements are ignored after execvp() call as this whole
				         process(execDemo.c) is replaced by another process (EXEC.c)
				         */
				         printf("Ending-----3");
	}
	else if(id1>0&&id2==0&&id3>0){
		printf("ejectandose hijo 2\n");

		char *args[]={"/home/juan/Documentos/minimo/src/./minimo",NULL};
						         execv(args[0],argv);
						         /*All statements are ignored after execvp() call as this whole
						         process(execDemo.c) is replaced by another process (EXEC.c)
						         */
						         printf("Ending-----minimo");
	}
	else if(id1==0&&id2==0&&id3>0){
		printf("ejectandose el hijo 1 del hijo 1 osea le nieto\n");
		char *args[]={"/home/juan/Documentos/maximo/src/./maximo",NULL};
						         execv(args[0],argv);
						         /*All statements are ignored after execvp() call as this whole
						         process(execDemo.c) is replaced by another process (EXEC.c)
						         */
						         printf("Ending-----3");

	}
	else{
		   return (0);
	}
}
























