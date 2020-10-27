/*
    Titulo: Ordenamiento Shell
    Descripción: Implemntación del algoritmo de ordenamiento Shell optimizado
    Fecha: 26/10/2020
    Version: 1.3
    Autor: Luis Fernando Reséndiz Chávez
    Observaciones: La implementación la tomé de un libro, ya que la del profesor no
    funcionaba.
*/

/*********************************************************/
        BIBLIOTECAS UTILIZADAS
/*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

/*********************************************************/
        PROTOTIPOS DE FUNCIONES
/*********************************************************/

void ShellSort(int* a, int n);

/*********************************************************/
        FUNCIÓN PRINCIPAL DEL PROGRAMA
/*********************************************************/

int main(int argc, char *argv[]) {
    if(argc != 2)
        return 0;

    double utime0, stime0, wtime0,utime1, stime1, wtime1;

    int n = atoi(argv[1]), i;
    int* a = malloc(sizeof(int) * n);

    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // algorithm start
    uswtime(&utime0, &stime0, &wtime0);

    ShellSort(a, n);

    // algorithm end
    uswtime(&utime1, &stime1, &wtime1);

    //Cálculo del tiempo de ejecución del programa
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));


    return 0;
}

/*********************************************************/
        IMPLEMENTACIÓN DE FUNCIONES
/*********************************************************/

// ShellSort(int*, int) -> void
// Recibe un apuntador al arreglo original a ordenar, y un entero que representa su tamaño.
// Ordena los numeros del arreglo mediante el algoritmo de ShellSort.
void ShellSort(int* a, int n) {
    int i, j, k, tmp;

    for (i = n / 2; i > 0; i = i / 2){
        for (j = i; j < n; j++){
            for(k = j - i; k >= 0; k = k - i){
                if (a[k+i] >= a[k])
                    break;
                else {
                    tmp = a[k];
                    a[k] = a[k+i];
                    a[k+i] = tmp;
                }
            }
        }
    }
}