// Importamos nuestras definiciones auxiliares.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <getopt.h>
#include "vivas.h"
#include "vecina.h"
#include "print.h"
#include "itera.h"

int main(int argc, char **argv)
{
  // Mensaje de bienvenida
  printf("¡¡Bienvenido al Juego De La Vida!!\n");
   
  // Argumentos de main
  int n = 15;

  int option_index;
  int c;

  static struct option long_options[] =
  {
    {"size", optional_argument, 0, 's'},
    { 0, 0, 0, 0 }
  };

  while ((c = getopt_long(argc, **argv, "s:", long_options,
                          &option_index)) != -1) {
    switch (c) {
    case 's':
      n = strtol(optagr, NULL, 0);
      break;
    default
      printf("ERROR\n");
      exit(EXIT_FAILURE);
    }
  }

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
  
