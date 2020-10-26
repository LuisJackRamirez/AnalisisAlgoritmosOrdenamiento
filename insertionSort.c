#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int A[10000007];

void Insercion (int *, int);

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

  Insercion (A, n);

  for (i = 0; i < n; i++)
    printf ("%d ", A[i]);

  printf ("\n");

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
