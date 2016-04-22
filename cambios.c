// Importamos nuestras definiciones auxiliares.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cambiosvivas.h"
#include "vecina.h"
#include "print.h"

int main()
{
  // Pedimos al usuario la dimensión de nuestro mundo.
  int n;
  printf("¿Cuál es el tamaño de nuestro tablero?:");
  scanf("%d",&n);
  
  // Inicializamos un tablero inicial cualquiera.
  int p[n][n];
  int *t = p;
  int q[n][n];
  int *s = q;

  int i;
  int j;

  for (j = 0; j < n; j++)
    for (i = 0; i < n; i++)
         { p[i][j] = 0; 
           i++;
           p[i][j] = 1; }; 

  for (j = 0; j < n; j++)
    { for (i = 0; i < n; i++)
        printf(" %d ", p[i][j]);
      printf("\n"); };

  printf("\n\n\n");

  print(t,n);
  
  //itera (t,s,n);

  return 0;

}
  
