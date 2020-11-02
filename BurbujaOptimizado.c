#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

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

int main(int argc, char *argv[]){
	if(argc != 2)
        return 0;

	int n, i;
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	
	n = atoi(argv[1]);

	int *A = malloc(sizeof(int) * n);
	
	printf("\nIngrese %d numeros enteros\n",n);
	
	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);
		
	uswtime(&utime0, &stime0, &wtime0);

	burbujaOptimizada(A,n);

	uswtime(&utime1, &stime1, &wtime1);

	//Cálculo del tiempo de ejecución del programa
    printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		
	return 0;	
}
