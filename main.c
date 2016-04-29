// Importamos nuestras definiciones auxiliares.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <getopt.h>
#include "mundo.h"

int main(int argc, char **argv)
{
  // Mensaje de bienvenida
  printf("¡¡Bienvenido al Juego De La Vida!!\n");
  
  // Pedimos el tamaño de nuestro mundo
  int n;
  printf("Ingresa el tamaño de tu mundo: ");
  scanf("%d", &n);
  printf("\n");

  // Pedimos el número finito de iteraciones
  int m;
  printf("¿Cuántos pasos quieres hacer en un mundo?: ");
  scanf("%d",&m);
  printf("\n");
   
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
};
  p[5][5] = 1;
  p[6][6] = 1;
  p[7][4] = 1;
  p[7][5] = 1;
  p[7][6] = 1;
  
// Imprimimos nuestro mundo y comenzamos a iterar.
  printf("\n");
  itera(t,s,n,m,0);

  return 0;
}
  
