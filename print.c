#include <stdio.h>

// Definimos la funcion que nos permitirá imprimir el tablero
// después de cada iteración

// Imprimirá un espacio para celulas muerta y una X para celulas
// vivas.

int print(int *t, int n)
{
  int i;
  int j;

  for (j = 0; j < n; j++)
    { for (i = 0; i < n; i++, t++)
        printf(" %d ", *t);
      printf("\n"); }

  printf("\n");
  
  return 0;
}
