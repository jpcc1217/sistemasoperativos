#include <stdio.h>
#include <stdlib.h>

struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
};

struct estudiante mkdb(struct estudiante *database,char nombreDB,int tamanodb);

struct estudiante main(int argc, char *argv[], struct estudiante *database,char nombreDB,int tamanodb){
    return mkdb(database,nombreDB,tamanodb);
}


struct estudiante mkdb(struct estudiante *database,char nombreDB,int tamanodb){
	scanf("%s", nombreDB);
	scanf("%d", &tamanodb);
	database = (struct estudiante*) malloc(
	tamanodb * sizeof(struct estudiante));
    return *database;
}