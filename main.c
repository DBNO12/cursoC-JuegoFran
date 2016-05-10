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

  // Argumentos de main
  int n = 10; // Valor del tamaño del mundo por defecto

  int option_index = 0;
  int c;

  static struct option long_options[] =
  {
    {"size", optional_argument, 0, 's'},
    {"manual", optional_argument, 0, 'm'},
    {"help", optional_argument, 0, 'h'},
    { 0, 0, 0, 0 }
  };

  while ((c = getopt_long(argc, argv, "s:m::h::", long_options,
                          &option_index)) != -1) {
    switch (c) {
    case 's':
      // Recogemos tamaño por argumento de main
      n = strtol(optarg, NULL, 0); 
      break;
    case 'm':
      // Recogemos tamaño por consola, pidiendolo al usuario
      printf("Ingresa el tamaño de tu mundo: ");
      scanf("%d", &n);
      break;
    case 'h':
      printf("++ Ayuda del Juego de La Vida -- Fran ++\n");
      printf("Ingresa -s para dar el tamaño de tu tablero directamente\n");
      printf("Ingresa --manual para dar el tamaño de tu tablero de manera manual por consola");
      return 0;
    default:
      printf("ERROR EN LA RECOGIDA DE ARGUMENTOS\n");
      exit(EXIT_FAILURE);
    }
  }


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
  
