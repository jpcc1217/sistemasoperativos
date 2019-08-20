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
char comando;
char nombreDB[20];
char nombreArchivo[30] = "./src/";
int contadorRegistro = 0;

FILE *archivo;

void mkdb() {
	scanf("%s", nombreDB);
	scanf("%d", &tamanodb);
	database = (struct estudiante*) malloc(
			tamanodb * sizeof(struct estudiante));
}

void loaddb() {
	scanf("%s", nombreDB);
	strcat(nombreArchivo, nombreDB);
	char mander[100];
	char *token;

//	(database + contadorRegistro)->cedula = "asdasd";

	archivo = fopen(nombreArchivo, "r");
	if (archivo == NULL) {
		printf("no se pudo cargar base de datos\n: ");
		exit(8);
	} else {
		printf("base de datos cargada correctamente\n: ");

		if (fgets(mander, 100, archivo) != NULL)
			puts(mander);
		token = strtok(mander, "\t");
		while (token != NULL) {
		&(database + contadorRegistro)->cedula == token;
			(database + contadorRegistro)->nombre == strtok(mander, "\t");
			&(database + contadorRegistro)->semestre == strtok(mander, "\t");
			token = strtok(NULL, mander);
			contadorRegistro++;
		}

	}

	fclose(archivo);
}

void savedb() {
	char caracter2;
	scanf("%s", nombreArchivo);
	archivo = fopen(nombreArchivo, "w+");

	printf("\nIntroduce un texto al fichero: ");

	while ((caracter2 = getchar()) != '\n') {
		printf("%c", fputc(caracter2, archivo));
	}

	fclose(archivo);
}
void readall() {
	for (int i = 0; i < contadorRegistro; i++) {
		printf(" %d |", (database + i)->cedula);
		printf(" %s |", (database + i)->nombre);
		printf(" %d\n", (database + i)->semestre);

	}

//	char caracteres[100];
//
//	archivo = fopen(nombreArchivo, "r");
//	if (archivo == NULL)
//		exit(1);
//	else {
//		printf("\nEl contenido del archivo de prueba es \n\n");
//		while (feof(archivo) == 0) {
//			fgets(caracteres, 100, archivo);
//			printf("%s", caracteres);
//		}
//	}
//	fclose(archivo);

}

void readsize() {

//	char caracter;
//	while (1) {
//		caracter = fgetc(archivo);
//		if (feof(archivo)) {
//			break;
//		}
//		++contadorRegistro;
//		printf("%c", caracter);
//	}
//	printf("Numero de caracteres en %s es: %d\n", nombreArchivo,
//			contadorRegistro);
//	fclose(archivo);

	printf("numero de caracteres en %s es:%d\n", nombreDB, contadorRegistro);

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
		printf("no se encontro el registro");

	}
}

int main(void) {
	while (1) {
		printf("ingrese el comando\n");
		scanf("%s", &comando);

		if (strcmp(&comando, "mkdb") == 0) {
			mkdb();

		}

		if (strcmp(&comando, "loaddb") == 0) {
			loaddb();

		}

		if (strcmp(&comando, "savedb") == 0) {
			savedb();

		}

		if (strcmp(&comando, "readall") == 0) {
			readall();

		}

		if (strcmp(&comando, "readsize") == 0) {
			readsize();

		}

		if (strcmp(&comando, "mkreg") == 0) {
			mkreg();

		}

		if (strcmp(&comando, "readreg") == 0) {
			readreg();

		}

		if (strcmp(&comando, "exit") == 0) {
			exit(8);
		}

		else
			(printf("comando no admitido\n"));

		printf("escriba otro comando\n");

	}

	free(database);

}
