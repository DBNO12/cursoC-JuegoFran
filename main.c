// Importamos nuestras definiciones auxiliares.
#include <stdio.h>
#include "vivas.h"
#include "vecina.h"
#include "print.h"
#include "itera.h"

int main()
{
  // Mensaje de bienvenida
  printf("¡¡Bienvenido al Juego De La Vida!!\n");
  // Pedimos al usuario la dimensión de nuestro mundo.
  int n;
  printf("¿Cuál es el tamaño de nuestro tablero?: ");
  scanf("%d",&n);
  
  // Inicializamos un tablero inicial cualquiera.
  int p[n][n];
  int *t = p;
  int q[n][n];
  int *s = q;

  int i;
  int j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) { 
           p[i][j] = 0; 
           j++;
           p[i][j] = 1; 
};
  p[0][0] = 1;
  p[n-1][n-1] = 0;
  
// Imprimimos nuestro mundo y comenzamos a iterar.
  printf("\n");
  itera(t,s,n);

  return 0;
}
  
