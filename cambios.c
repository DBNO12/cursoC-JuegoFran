// Importamos nuestras definiciones auxiliares.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cambiosvivas.h"

int main()
{
  // Pedimos al usuario la dimensión de nuestro mundo.
  int n;
  printf("¿Cuál es el tamaño de nuestro tablero?:");
  scanf("%d",&n);
  
  // Inicializamos un tablero inicial cualquiera.
  int p[n][n];
  int i;
  int j;
  int r;

  for (j = 0; j < n; j++)
    {for (i = 0; i < n; i++)
         { p[i][j] = 1; 
           i++;
           p[i][j] = 0; }; };
      

  for (j = 0; j < n; j++)
    { for (i = 0; i < (n-1); i++)
        {printf(" %d ", p[i][j]);}
        printf(" %d\n", p[i][j]); };

  //printf("%d\n", vivas(p,n,3,3));

  return 0;

}
  
