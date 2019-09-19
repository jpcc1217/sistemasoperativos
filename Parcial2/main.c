#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Juan Pablo Cano Cuadros
// 000156364
struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
};

struct estudiante *database;

int tamanodb;
char comando[10];
char nombreDB[20];
char nombreArchivo[30] = "./src/";
int contadorRegistro = 0;
FILE *archivo;


int main(int argc, char *argv[])
{

    char *argvFork[argc + 1];

    for (int i = 1; i < argc; i++)
    {
        argvFork[i] = argv[i];
    }
    argvFork[argc] = NULL;

    pid_t hijo;
    while (1)
    {
        printf("Ingrese el comando\n");
        scanf("%s", comando);
        hijo = fork();

        switch (hijo)
        {
        case -1:
            printf("error al crear hijo %d\n");
            exit(EXIT_FAILURE);
            break;
        case 0:

            if (strcmp(comando, "mkdb") == 0)
            {
                argvFork[0] = "./mkdb";
                database = execv(argvFork[0], argvFork, database, contadorRegistro);
                contadorRegistro = 0;
                perror("execv fails");
                exit(EXIT_FAILURE);
                kill(hijo, SIGKILL);
            }

            else if (strcmp(comando, "readall") == 0)
            {
                argvFork[0] = "./readall";
                execv(argvFork[0], argvFork, database, contadorRegistro);
                perror("execv fails");
                exit(EXIT_FAILURE);
                kill(hijo, SIGKILL);
            }
            else if (strcmp(comando, "readsize") == 0)
            {
                argvFork[0] = "./readsize";
                execv(argvFork[0], argvFork, nombreDB,contadorRegistro);
                perror("execv fails");
                exit(EXIT_FAILURE);
                kill(hijo, SIGKILL);
            }

            else if (strcmp(comando, "mkreg") == 0)
            {
                argvFork[0] = "./mkreg";
                database = execv(argvFork[0], argvFork, database, contadorRegistro);
                contadorRegistro++;
                perror("execv fails");
                exit(EXIT_FAILURE);
                kill(hijo, SIGKILL);
            }

            else if (strcmp(comando, "readreg") == 0)
            {
                argvFork[0] = "./readreg";
                execv(argvFork[0], argvFork,database, contadorRegistro);
                perror("execv fails");
                exit(EXIT_FAILURE);
                kill(hijo, SIGKILL);
            }

            else if (strcmp(comando, "exit") == 0)
            {
                exit(8);
            }

            else
            {
                (printf("Comando no admitido\n"));
            }
        }
    }

    free(database);
}