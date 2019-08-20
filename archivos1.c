#include <stdio.h>
#include <stdlib.h>

const char nombreArchivo[] = "./src/input.txt"; //nombre del archivo a abrir

int main(void) {
	int contador = 0;
	FILE *archivo;  //se declara un puntero de tipo FILE

	//Fopen devulve un puntero de tipo FILE
	char caracter;
//	int ch;

	archivo = fopen(nombreArchivo, "r");
	/*r es para lectura, w es para escritura,
	 r+ lectura y escritura y w+ lectura, escritura y crea el archivo si no existe */

	if (archivo == NULL) { //validar si abre el archivo
		printf("no se puede abrir %s\n", nombreArchivo);
		exit(8);
	}

//	------------------------fopen + fgetc -----------------------------------//

	while (1) {
		caracter = fgetc(archivo);
		if (feof(archivo)) {
			break;
		}
		++contador;
		printf("%c", caracter);
	}
	printf("Numero de caracteres en %s es: %d\n", nombreArchivo, contador);
	fclose(archivo);

//	while (1) {
//			ch = fgetc(archivo);
//			if (ch == EOF)
//				break;
//			++contador;
//
//		}
//		printf("Numero de caracteres en %s es: %d\n", nombreArchivo, contador);

	// --------------------------------fgets ---------------------------------//
	char caracteres[100];

	archivo = fopen("prueba.txt", "r");

	if (archivo == NULL)
		exit(1);
	else {
		printf("\nEl contenido del archivo de prueba es \n\n");
		while (feof(archivo) == 0) {
			fgets(caracteres, 100, archivo);
			printf("%s", caracteres);
		}
		system("PAUSE");
	}
	fclose(archivo);

	//---------------------------------fputc-------------------//
	char caracter2;

	archivo = fopen(nombreArchivo, "a+t"); //parámetro para escritura al final y para file tipo texto

	printf("\nIntroduce un texto al fichero: ");

	while ((caracter2 = getchar()) != '\n') {
		printf("%c", fputc(caracter2, archivo));
	}

	fclose(archivo);

	//-----------------------------fputs----------------------//

	char cadena[] = "Mostrando el uso de fputs en un fichero.\n";

	archivo = fopen(nombreArchivo, "r+");

	fputs(cadena, archivo);

	fclose(archivo);

	return (0);

}
