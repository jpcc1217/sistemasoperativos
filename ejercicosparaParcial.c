#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inputRegister {
	int orderno;
	char emailaddress[30];
	char password[30];
};

struct inputRegister *database;

int contadorRegistro = 0;

int main(void) {
	int tamanodb;
	char comando;
	int n = 1;

	while(n!=0){
	printf("ingrese el comando\n");
	scanf("%s", &comando);

	if (strcmp(&comando, "cDB") == 0) {
		printf("ingrese el tamaño de la base de datos:\n");
		scanf("%d", &tamanodb);

		database = (struct inputRegister *) malloc(tamanodb * sizeof(struct inputRegister));

		/*database->orderno = 23;
		printf("Ingrese email: ");
		scanf("%s",&(database->emailaddress[4]));
*/

	}

	if (strcmp(&comando, "lR") == 0) {


		 for(int i=0;i<contadorRegistro;i++){
			 /* printf("%d %s %s",database->orderno[i],database->emailaddress[i],database->password[i]); */
			 printf(" %d |", (database + i)->orderno );
			 printf(" %s |", (database + i)->emailaddress);
			 printf(" %s\n", (database + i)->password);



		 }

	}

	if (strcmp(&comando, "cantidadRegistros") == 0) {
		printf("cantidad de registros:%d",tamanodb);
	}

	if (strcmp(&comando, "iR") == 0) {
//		int tempa;
//		char tempb[30],tempc[30];
		printf("ingrese el registro asi: order email password\n");
		scanf("%d", &((database + contadorRegistro)->orderno));
		scanf("%s", ((database + contadorRegistro)->emailaddress));
		scanf("%s", ((database + contadorRegistro)->password));

		contadorRegistro++;

	}


	if (strcmp(&comando, "leerRegistroEsp") == 0) {

	}

	if (strcmp(&comando, "editarRegistro") == 0) {

		}

//	else(printf("aprenda a escribir\n"));

//	printf("escriba 0 para salir o cualquier otro caracter para ingresar otro comando\n");
//		scanf("%d", &n);
//
    }

	free(database);

}
