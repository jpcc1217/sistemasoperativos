#include <stdio.h>
#include <stdlib.h>

struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
};

void readall(struct estudiante *database,int contador);

int main(int argc, char *argv[], struct estudiante *database,int contadorRegistro){
    readall(database,contadorRegistro);
}


void readall(struct estudiante *database,int contadorRegistro){
    for (int i = 0; i < contadorRegistro; i++)
    {
        printf(" Cedula: %d |", (database + i)->cedula);
        printf(" Nombre: %s |", (database + i)->nombre);
        printf(" Semestre: %d\n", (database + i)->semestre);
    }
}