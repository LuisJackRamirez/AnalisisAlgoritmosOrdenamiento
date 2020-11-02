#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

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

int main(int argc, char *argv[]){
    if(argc != 2)
        return 0;

	int n,i;
	
	n = atoi(argv[1]);

	int A[n];
	
	for(i = 0; i < n; i++) 
		scanf("%d",&A[i]);

	double utime0, stime0, wtime0,utime1, stime1, wtime1;
    uswtime(&utime0, &stime0, &wtime0);

	burbujaSimple(A,n);

    uswtime(&utime1, &stime1, &wtime1);
    printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	
	return 0;	
}
