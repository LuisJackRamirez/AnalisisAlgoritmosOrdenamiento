#include <stdio.h>
#include <stdlib.h>

void burbujaOptimizada(int *A, int n) {	
	int i, j, aux;            

	for(i = 0;i < n; i++){                
		for(j = 0; j < i; j++){               
			if(A[i] < A[j]){   
				aux = A[j];     
				A[j] = A[i];  
				A[i] = aux;     
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
	int n, i;
	
	printf("Ingrese tamaño: ");
	scanf("%d",&n);
	
	int *A = malloc(sizeof(int) * n);
	
	printf("\nIngrese %d numeros enteros\n",n);
	
	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);
		
	burbujaOptimizada(A,n);
		
	putchar('\n');
	
	imprimirNumeros(A,n);	
		
	return 0;	
}
