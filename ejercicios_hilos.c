#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>

//ejer 1
/*

struct parametros_hilo{
    char caracter;
    int contador;
};


void* imprimir_caracter (void* parametros)
{
    struct parametros_hilo* p = (struct parametros_hilo*)parametros;
    int i;
    for(i=0;i< p->contador;i++)
        printf("%c",p->caracter);
    return NULL;
    }
int main()
{
    pthread_t id_hilo1;
    pthread_t id_hilo2;
    struct parametros_hilo hilo1_param;
    struct parametros_hilo hilo3_param;
    struct parametros_hilo hilo2_param;
    hilo1_param.caracter = 'x';
    hilo1_param.contador = 3000;
    hilo3_param.caracter='V';
    hilo3_param.contador=200;

    pthread_create(&id_hilo1,NULL,&imprimir_caracter,&hilo3_param);


    hilo2_param.caracter = 'o';
    hilo2_param.contador = 2000;
    pthread_create(&id_hilo2,NULL,&imprimir_caracter,&hilo2_param);
    pthread_join(id_hilo2, NULL);
    pthread_join(id_hilo1, NULL);
    //de esta forma no se controla que hilo se ejucuta la CPU se  multplexa

    return 0;
}

*/

//ejer 2
/*
int x=0;
void ft(pthread_t hilos_id){

    int i;
    printf("Identificador de  hijo :%d \nx tiene el valor de %d antes de ser incrementado 1000 veces por el hijo \n",(int)hilos_id,x);
    for(i=1;i<=100;i++)x++;
}
int main(void){

    pthread_t hilos_ids[4];
    int i;
    for(i=0;i<4;i++)pthread_create(&hilos_ids[i],NULL,(void *)ft ,&hilos_ids[i]);
    for(i=0;i<4;i++)pthread_join(hilos_ids[i],NULL);
    printf("hilo principal :x %d",x);
    return 0;
}


*/

//ejer 3

/* Calcula los números primos sucesivamente.
Retorna el N-ésimo número primo
donde N es el valor apuntado por *ARG. */

//ejer 4
/*
void* calcular_primo(void* arg) {
	int candidato = 2;
	int n = *((int*) arg);
	while (1) {
		int factor;
		int es_primo = 1;
		for(factor = 2; factor < candidato; ++factor)
			if(candidato % factor == 0) {
				es_primo = 0;
				break;
			}

			if(es_primo) {
				if(--n == 0)
					return (void*) candidato;
			}
			++candidato;
	}
	return NULL;
}

int main()
{
	struct timeval ti, tf;

	double tiempo;

    pthread_t hilo_id;
    int cual_primo=5000;
    int primo;
    gettimeofday(&ti, NULL);   // Instante inicial

    pthread_create (&hilo_id,NULL,&calcular_primo,&cual_primo);
    pthread_join(hilo_id,(void*)&primo);

    gettimeofday(&tf, NULL);   // Instante final

    tiempo= (tf.tv_sec - ti.tv_sec)*1000*1000 + (tf.tv_usec - ti.tv_usec);
    printf("Has tardado: %g microsegundos\n", tiempo);
    printf("el numeor primo es %d",primo);
    return 0;
}

*/

//--------------------Alimento para el pensamiento 2-------------------------------------

/*

void* leer_cantidadlineas(char *NombreArchivo){
	char linea[1024];
	FILE *archivo;
	char caracter;
	int saltos=0;
	archivo=fopen(NombreArchivo,"r");
	if (archivo == NULL)
	        {
	            printf("\nError de apertura del archivo. \n\n");
	        }
	        else
	        {
	        	while((caracter=fgetc(archivo))!=EOF) {
	        	        if(caracter=='\n'){
	        	        	saltos++;
	        	        }
	        	    }
	        }
	  fclose(archivo);
	return (void*)saltos;

}
int main(int argc, char *argv[]){
	int total_lineas=0;
	pthread_t hilos_ids[argc-1];
	int lineas_actuales[argc-1];
	for(int i=1;i<argc;i++){
	pthread_create(&hilos_ids[i],NULL,(void *)&leer_cantidadlineas,argv[i]);
	pthread_join(hilos_ids[i],(void*)&lineas_actuales[i]);
	printf("\n%s:%d lineas\n",argv[i],lineas_actuales[i]);

	}
	for(int i=1;i<argc;i++){
		total_lineas=lineas_actuales[i]+total_lineas;
	}

	printf("\ntotal lineas :%d\n",total_lineas);
}


*/

//----------------Alimento para el pensamiento 3-----------------------------------------
	struct argumentos{
		int inicio;
		int fin;
		FILE *direccion;
	};
void* sumarArreglo(struct argumentos *x ){
	char caracter;
	int numero ;
	int  suma =0;
	//printf("inicio %d fin %d\n",x->inicio,x->fin);
	//printf("Direccion de archivo en funcion =%p\n",x->direccion);
	fseek(x->direccion,x->inicio, SEEK_CUR);
	while(x->inicio<=x->fin){
		caracter=fgetc(x->direccion);
		//printf("valor %c\n",caracter);
		numero=caracter-'0';
		suma=suma+numero;
		x->inicio++;
	}
	return (void*)suma;
}

void sumarArreglo2( FILE *archivo){
	char caracter;
		int numero ;
		int  suma=0;
	if (archivo == NULL)
		        {
		            printf("\nError de apertura del archivo. \n\n");
		        }
		        else
		        {
		        	while((caracter=fgetc(archivo))!=EOF) {
		        		if(caracter=='\n'){
		        			//esto para que no sume nada si el caracterleido es \n
		        		}
		        		else{
		        			numero=caracter-'0';
		        			suma=suma+numero;
		        		}

		        	    }
		        }


	printf("La suma por el metodo directo es =%d\n",suma);

}

int main(int argc, char *argv[]){
		FILE *archivo;
		char caracter;
		int saltos=0;
		int inicio ,fin;
		int suma1 ,suma2;
		pthread_t hilo1 ,hilo2;
		struct argumentos arg1 ,arg2; //creamos dos estructuras para pasra mas de un parametro en thread_create
		archivo=fopen(argv[1],"r");
		if (archivo == NULL)
		        {
		            printf("\nError de apertura del archivo. \n\n");
		        }
		        else
		        {
		        	while((caracter=fgetc(archivo))!=EOF) {
		        	        	saltos++;
		        	    }
		        	 rewind(archivo);//ponemos el curosos letura/ecscrtura el inicio del archivo
		        	saltos=saltos-1;
		        	//printf("Direccion de archivo en main=%p\n",archivo);
		        		inicio=0;
		        		fin=saltos/2;
		        		arg1.inicio=inicio;
		        		arg1.fin=fin;
		        		arg1.direccion=archivo;
		        		pthread_create(&hilo1,NULL,(void *)&sumarArreglo,&arg1);
		        		pthread_join(hilo1,(void*)&suma1);
		        		inicio=fin+1;
		        		fin=saltos-1;
		        		arg2.inicio=inicio;
		        		arg2.fin=fin;
		        		arg2.direccion=archivo;
		        		rewind(archivo);//ponemos el curosos letura/ecscrtura el inicio del archivo
		        		pthread_create(&hilo2,NULL,(void *)&sumarArreglo,&arg2);
		        		pthread_join(hilo2,(void*)&suma2);
		        		printf("\nSuma de la primera mitad=%d\n",suma1);
		        		printf("Suma de la segunda mitad=%d\n",suma2);
		        		printf("Total =%d\n",suma1+suma2);

		        }
		fclose(archivo);
		archivo=fopen(argv[1],"r");
		sumarArreglo2(archivo);
		fclose(archivo);


}

