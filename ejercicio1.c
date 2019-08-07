/*
 ============================================================================
 Name        : ejercicio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int tamano1,tamano2;
int arrayResultado[MAX];

void printArray(int *pdata,int n){
	for(int i=0;i<n;i++){
		printf("dato[%d]:  %d\n",i,pdata[i]);
	}
}

int elementosComunes(int *pdata,int *pdata2){
	int resultado;
	int k = 0;

	for(int i=0;i<tamano1;i++){
		for(int j=0;j<tamano2;j++){
			if(pdata[i]==pdata2[j]){
				arrayResultado[k]=pdata[i];
				k++;
			}

			}
		}



	resultado = 1;
	return resultado;
}

int main(void) {
	printf("ingrese el tamano del arreglo 1 \n");
	scanf("%d",&tamano1);
	int arreglo1[tamano1];
	for(int i =0;i<tamano1;i++){
		printf("ingrese el elemento %d\n",i);
		scanf("%d",&arreglo1[i]);
	}

	printf("ingrese el tamano del arreglo 2 \n");
		scanf("%d",&tamano2);
		int arreglo2[tamano2];
		for(int i =0;i<tamano2;i++){
			printf("ingrese el elemento %d\n",i);
			scanf("%d",&arreglo2[i]);
		}



	elementosComunes(arreglo1,arreglo2);
	printArray(arrayResultado,MAX);


}
