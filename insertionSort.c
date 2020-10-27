#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tiempo.h"

int A[10000007];

void Insercion (int *, int);

int
main (int argc, char **argv)
{
  double utime0, stime0, wtime0, utime1, stime1, wtime1;
  int i = 0;
  int n = atoi (argv[1]);

  memset (A, -1, sizeof (A));

  for (int i = 0; i < n; i++)
    scanf ("%d", &A[i]);

  uswtime (&utime0, &stime0, &wtime0);
  Insercion (A, n);
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
Insercion (int *A, int n)
{
  int j = 0;
  int temp = 0;

  for (int i = 0; i < n; i++)
    {
      j = i;
      temp = A[i];

      while (j > 0 && temp < A[j - 1])
        {
	  A[j] = A[j-1];
	  j--;
	}

      A[j] = temp;
    }

  return;
}
