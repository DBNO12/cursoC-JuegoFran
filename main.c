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

  // Inicializamos un tablero inicial cualquiera.
  int p[n][n];
  int *w1 = p;
  int q[n][n];
  int *w2 = q;

  // Inicializamos el struct gol
  struct gol world;
  world.w1 = w1;
  world.w2 = w2;
  world.tam = n;
  struct gol *w = world;

  // Bichito
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
  
  print(w);
  for (i = 0; i < n; i++) {
    itera(w);
    print(w);
  }

  return 0;
}
  
