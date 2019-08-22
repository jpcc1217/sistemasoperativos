#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Juan Pablo Cano Cuadros
// 000156364
struct estudiante {
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

void mkdb() {
	contadorRegistro = 0;
	scanf("%s", nombreDB);
	scanf("%d", &tamanodb);
	database = (struct estudiante*) malloc(
			tamanodb * sizeof(struct estudiante));
}

void loaddb() {
	contadorRegistro = 0;
	scanf("%s", nombreDB);
	strcat(nombreArchivo, nombreDB);

	archivo = fopen(nombreArchivo, "r");
	if (archivo == NULL) {
		printf("No se pudo cargar base de datos\n: ");
		exit(8);
	} else {
		printf("Base de datos cargada correctamente\n: ");
		while (fscanf(archivo, "%d %s %d ",
				&(database + contadorRegistro)->cedula,
				(database + contadorRegistro)->nombre,
				&(database + contadorRegistro)->semestre) == 1) {
			contadorRegistro++;
		}

	}

	fclose(archivo);
}

void savedb() {
	scanf("%s", nombreArchivo);
	archivo = fopen(nombreArchivo, "w+");
	for (int i = 0; i < contadorRegistro; i++) {
		fprintf(archivo, "%d %s %d ", (database + i)->cedula,
				(database + i)->nombre, (database + i)->semestre);
	}

	fclose(archivo);
}
void readall() {
	for (int i = 0; i < contadorRegistro; i++) {
		printf(" Cedula: %d |", (database + i)->cedula);
		printf(" Nombre: %s |", (database + i)->nombre);
		printf(" Semestre: %d\n", (database + i)->semestre);

	}

}

void readsize() {
	printf("Numero de registros en %s es:%d\n", nombreDB, contadorRegistro);
}

void mkreg() {
	scanf("%d", &((database + contadorRegistro)->cedula));
	scanf("%s", ((database + contadorRegistro)->nombre));
	scanf("%d", &((database + contadorRegistro)->semestre));
	contadorRegistro++;
}

void readreg() {
	int cedulatemp;
	scanf("%d", &cedulatemp);
	for (int i = 0; i < contadorRegistro; i++) {
		if (((database + i)->cedula) == cedulatemp) {
			printf(" %d |", (database + i)->cedula);
			printf(" %s |", (database + i)->nombre);
			printf(" %d\n", (database + i)->semestre);
			break;
		}
		printf("No se encontro el registro");

	}
}

int main(void) {
	while (1) {
		printf("Ingrese el comando\n");
		scanf("%s", comando);

		if (strcmp(comando, "mkdb") == 0) {
			mkdb();

		}

		else if (strcmp(comando, "loaddb") == 0) {
			loaddb();

		}

		else if (strcmp(comando, "savedb") == 0) {
			savedb();

		}

		else if (strcmp(comando, "readall") == 0) {
			readall();

		}

		else if (strcmp(comando, "readsize") == 0) {
			readsize();

		}

		else if (strcmp(comando, "mkreg") == 0) {
			mkreg();

		}

		else if (strcmp(comando, "readreg") == 0) {
			readreg();

		}

		else if (strcmp(comando, "exit") == 0) {
			exit(8);
		}

		else {
			(printf("Comando no admitido\n"));
		}

	}

	free(database);

}
