/*
	Titulo: Ordenamiento de selección
	Descripción: Implementación del algoritmo de ordenamiento selección para ordenar n números.
	Fecha: 27/10/2020
	Version: 1.2
	Autor: Luis Armando Ramírez Espinosa
*/

/*********************************************************/
/*	BIBLIOTECAS UTILIZADAS				 */
/*********************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tiempo.h"

/*********************************************************/
/*	PROTOTIPOS DE FUNCIONES				 */
/*********************************************************/

void Seleccion (int *, int);
void printArr (int *, int);

/*********************************************************/
/*	VARIABLES GLOBALES				 */
/*********************************************************/

//Se optó por inicializar un arreglo del
//máximo tamaño del problema establecido
int A[10000007];

/*********************************************************/
/*	FUNCIÓN PRINCIPAL DEL PROGRAMA		 	 */
/*********************************************************/

int
main (int argc, char **argv)
{
  //Variables para la medición del tiempo	
  double utime0, stime0, wtime0, utime1, stime1, wtime1;

  //Si no se proporcionan dos argumentos en la línea de comandos
  //(el nombre del ejecutable y el argumento n), el programa termina
  //la ejecución
  if (argc != 2)
    return 0;

  //Inicializamos n con el segundo elemento
  //del argumento argv de la función main  
  int n = atoi (argv[1]);

  //Lectura de los números
  for (int i = 0; i < n; i++)
    scanf ("%i", &A[i]);

  //Comienza la medición de los tiempos haciendo uso
  //de la función proporcionada por "tiempo.h"
  uswtime (&utime0, &stime0, &wtime0);

  //Lamada a la función Seleccion () para ordenar el arreglo
  Seleccion (A, n);
  
  //En este punto se detiene la medición de tiempo del algoritmo
  uswtime (&utime1, &stime1, &wtime1);

  //Cálculo de los tiempos de ejecución del programa     
  printf ("Tiempo real: %.10f s\n", wtime1 - wtime0);
  printf ("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
  printf ("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
  printf ("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));

  return 0;
}
/*********************************************************/
/*	IMPLEMENTACIÓN DE FUNCIONES                      */
/*********************************************************/ 
//Seleccion (int *, int) -> void
//Recibe el arreglo de enteros por ordenar,
//y un entero que representa su tamaño.
//Ordena el algoritmo intercambiando las posiciones del i-ésimo
//número de la lista con el i-ésimo número más pequeño en el arreglo,
//i indexado en 1.
void
Seleccion (int *A, int n)
{
  int k = 0;
  int p = 0;
  int temp = 0;

  for (k = 0; k < n - 1; k++)
    {
      p = k;
      for (int i = k + 1; i < n; i++)
        {
	  if (A[i] < A[p])
	    p = i;
	}

      temp = A[p];
      A[p] = A[k];
      A[k] = temp;
    }

  return;
}

//printArr (int *, int) -> void
//Recibe un arreglo de enteros a imprimir, 
//y un entero que representa su tamaño
//Itera por todo el contenido del arreglo e imprime cada elemento
void
printArr (int *A, int n)
{
  for (int i = 0; i < n; i++)
    printf ("%d\n", A[i]);

  return;
}
