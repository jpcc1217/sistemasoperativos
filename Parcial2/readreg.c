#include <stdio.h>
#include <stdlib.h>

struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
};

void readreg(struct estudiante *database,int contadorRegistro);

int main(int argc, char *argv[], struct estudiante *database,int contadorRegistro){
    readreg(database,contadorRegistro);
}

void readreg(struct estudiante *database,int contadorRegistro){
    int cedulatemp;
    scanf("%d", &cedulatemp);
    for (int i = 0; i < contadorRegistro; i++)
    {
        if (((database + i)->cedula) == cedulatemp)
        {
            printf(" %d |", (database + i)->cedula);
            printf(" %s |", (database + i)->nombre);
            printf(" %d\n", (database + i)->semestre);
            break;
        }
        printf("No se encontro el registro");
    }
}