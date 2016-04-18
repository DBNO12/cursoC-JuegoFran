// Importamos nuestras definiciones auxiliares.
#include <stdio.h>
#include <stdlib.h>
#include "casilla.h"
#include "vivas.h"
#include "print.h"
#include "itera.h"

int main()
{
  // Pedimos al usuario la dimensión de nuestro mundo.
  int n;
  printf("¿Cuál es el tamaño de nuestro tablero?:");
  scanf("%d",&n);
  
  // Inicializamos un tablero inicial cualquiera.
  struct casilla p[n][n];
  int i;
  int j;
  int r;

  for (i = 0, j = 0, r = 0; r < (n*n); r++, j++)
    if ( j == (n-1) )
      { p[i][j].x = j;
        p[i][j].y = i;
        p[i][j].cel = 1;
        j = -1;
        i++; }
    else if ( r % 2 == 1)
      { p[i][j].x = j;
        p[i][j].y = i;
        p[i][j].cel = 1; }
    else
      { p[i][j].x = j;
        p[i][j].y = i;
        p[i][j].cel = 0; };

  p[0][0].cel = 1;
  p[(n-1)][(n-1)].cel = 1;

  // Inicializamos el puntero al tablero y comenzamos a 
  // pasar por pantalla las iteraciones.
  struct casilla *t = p;

  print(t,n);
  itera(t,n);
  
  return 0;
}
 
