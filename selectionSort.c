#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int A[10000007];

void Seleccion (int *, int);

int
main (void)
{
  int i = 0;
  int n = 0;

  memset (A, -1, sizeof (A));

  while (scanf ("%d", &A[i]) != -1)
    {
      n++;
      i++;
    }

  Seleccion (A, n);

  for (i = 0; i < n; i++)
    printf ("%d ", A[i]);

  printf ("\n");

  return 0;
}

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
