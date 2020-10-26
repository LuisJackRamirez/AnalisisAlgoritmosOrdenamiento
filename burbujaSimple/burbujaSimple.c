#include <stdio.h>
#include <stdlib.h>

void burbujaSimple(int *A, int n) {
	int i, j, aux;

	for(i = 1; i < n; i++) {
		for(j = 0; j < n - 1; j++) {
			if(A[j] > A[j + 1]) {
				aux = A[j];
				A[j] = A[j + 1];
				A[j + 1] = aux;
			}
		}
	}
}

void imprimirNumeros(int *A, int n){
	int i;
	
	for(i = 0; i < n; i++) 
		printf("%d\n",A[i]);
}

int main(){
	int n,i;
	
	printf("Ingrese tamaño: ");
	scanf("%d",&n);

	int A[n];

	printf("\nIngrese %d numeros enteros\n",n);
	
	for(i = 0; i < n; i++) 
		scanf("%d",&A[i]);
	

	burbujaSimple(A,n);
		
	putchar('\n');
	
	imprimirNumeros(A,n);
	
	return 0;	
}
