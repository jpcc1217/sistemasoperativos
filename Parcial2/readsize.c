#include <stdio.h>
#include <stdlib.h>

struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
};

void readsize(char nombreDB,int contadorRegistro);

int main(int argc, char *argv[],char nombreDB, int contadorRegistro){
    readsize(nombreDB, contadorRegistro);
}


void readsize(char nombreDB,int contadorRegistro){
    printf("Numero de registros en %s es:%d\n", nombreDB, contadorRegistro);
}