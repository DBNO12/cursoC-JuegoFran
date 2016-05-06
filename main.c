// Importamos nuestras definiciones auxiliares.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <getopt.h>
#include "mundo.h"

#define ITS 25

int main(int argc, char **argv)
{
  // Mensaje de bienvenida
  printf("¡¡Bienvenido al Juego De La Vida!!\n");
  
  // Pedimos el tamaño de nuestro mundo
  int n;
  printf("Ingresa el tamaño de tu mundo: ");
  scanf("%d", &n);
  printf("\n");

  struct gol *w;
  w = gol_alloc(n);
  if (!w) {
    perror("Error en gol_alloc -- main.c");
    exit(EXIT_FAILURE);
  }
  gol_init(w);
  
  int i;
  int pausa;
  for (i = 0; i < ITS; i++) {
    print(w);
    itera(w);
    printf("Escribe un número para continuar: ");
    scanf("%d",&pausa);
    printf("\n");
  }

  gol_free(w);
  
  return 0;
}
  
