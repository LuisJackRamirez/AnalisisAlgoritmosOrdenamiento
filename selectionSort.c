#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tiempo.h"

long long int A[10000007];

void Seleccion (long long int *, int);

int
main (int argc, char **argv)
{
  double utime0, stime0, wtime0, utime1, stime1, wtime1;
  int n = atoi (argv[1]);

  memset (A, -1, sizeof (A));

  for (int i = 0; i < n; i++)
    scanf ("%lli", &A[i]);

  uswtime (&utime0, &stime0, &wtime0);
  Seleccion (A, n);
  uswtime (&utime1, &stime1, &wtime1);
  
  printf ("--------\n");
  printf ("Tiempo real: %.10f s\n", wtime1 - wtime0);
  printf ("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
  printf ("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
  printf ("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
  printf ("--------\n");

  return 0;
}

void
Seleccion (long long int *A, int n)
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
