#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inputRegister {
	int orderno;
	char emailaddress[30];
	char password[30];
};

struct inputRegister *database;

int main(void) {
	int tamanodb;
	char comando;
	int n = 1;

	while(n!=0){
	printf("ingrese el comando\n");
	scanf("%s", &comando);

	if (strcmp(&comando, "crearDB") == 0) {
		printf("ingrese el tamaño de la base de datos:\n");
		scanf("%d", &tamanodb);

		database = (struct inputRegister *) malloc(tamanodb * sizeof(struct inputRegister));

		/*database->orderno = 23;

		printf("Ingrese email: ");
		scanf("%s",&(database->emailaddress[4]));
*/

	}

	if (strcmp(&comando, "leerRegistros") == 0) {


		 for(int i=0;i<tamanodb;i++){
			 /* printf("%d %s %s",database->orderno[i],database->emailaddress[i],database->password[i]); */
			 printf("%d\n", (database + i)->orderno );
			 printf("%s\n", (database + i)->emailaddress);
			 printf("%s\n", (database + i)->password);



		 }

	}

	if (strcmp(&comando, "cantidadRegistros") == 0) {
		printf("cantidad de registros:%d",tamanodb);
	}

	if (strcmp(&comando, "ingresarRegistro") == 0) {

	}

	if (strcmp(&comando, "leerRegistros") == 0) {

	}

	if (strcmp(&comando, "leerRegistroEsp") == 0) {

	}

	if (strcmp(&comando, "editarRegistro") == 0) {

		}

	else(printf("aprenda a escribir\n"));

	printf("escriba 0 para salir o cualquier otro caracter para ingresar otro comando\n");
		scanf("%d", &n);

	}

	free(database);

}

