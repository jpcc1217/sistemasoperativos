#include <stdio.h>
#include <stdlib.h>

struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
};

struct estudiante mkreg(struct estudiante *database,int contador);

struct estudiante main(int argc, char *argv[], struct estudiante *database,int contadorRegistro){
    return mkreg(database,contadorRegistro);
}


struct estudiante mkreg(struct estudiante *database,int contadorRegistro){

    scanf("%d", &((database + contadorRegistro)->cedula));
    scanf("%s", ((database + contadorRegistro)->nombre));
    scanf("%d", &((database + contadorRegistro)->semestre));
    contadorRegistro++;
    return *database;
}