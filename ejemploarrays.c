#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void printArray(int *pdata,int n){
	printf("\n the array is: \n");

			for(int i = 0; i< n;i++){
				printf("data[%d]: %d\n",i,*(pdata+i));
			}

			//tambien se puede con pdata[i]

}

int main(void) {

	int n;
	int data[MAX];
	int position;

	printf("Enter the length of the array");
	scanf("%d", &n);
	printf("enter %d elements of the array \n", n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	/*printf("\n the array is: \n");

	for(int i = 0; i<n;i++){
		printf("data[%d]: %d\n",i,data[i]);
	}
	*/

	printArray(data,n);

	printf("\n Enter the position to insert the element");
	scanf("%d",&position);
	position--;
	for(int i = n-1;i >= position;i-- ){
		data[i+1] = data[i];
	}

	printf("\n Enter the value: ");
	scanf("%d",&data[position]);


	/*printf("\n the array is: \n");

		for(int i = 0; i<=n;i++){
			printf("data[%d]: %d\n",i,data[i]);
		}
		*/

	printArray(data,n+1);

     return 0;
}
