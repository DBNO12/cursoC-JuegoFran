#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mundo.h"

struct gol {
  int *w1;
  int *w2;
  int tam;
};

int itera(struct gol *w)
{
    int i, j, vecinas, cell;

// Cambiamos el array - tablero según las reglas de nuestro juego
// a través de un puntero
  for (i = 0; i < w->tam; i++)
    for (j = 0; j < w->tam; j++, w->w2++) {
       vecinas = vivas(w,i,j);
       cell  = vecina(w,i,j);
       if ((cell) && (vecinas >= 2) && 
           (vecinas <= 3))
          *w->w2 = 1;
        else if (cell)
          *w->w2 = 0;
        else if (vecinas == 3)
          *w->w2 = 1;
        else
          *w->w2 = 0; 
    }

// Cambiamos los punteros
  int *aux = w->w2;
  w->w2 = w->w1;
  w->w1 = aux;
  
  return 0
}

int print(struct gol *w)
{
  int i;
  int j;

  for (i = 0; i < w->tam; i++) { 
    for (j = 0; j < w->tam; j++, w->w1++)
        printf(" %d ", *w->w1);
      printf("\n"); 
}

  printf("\n");
  
  return 0;
}

int vecina(struct gol *w, int x, int y)
{
  // Calculamos modulos
  x = x % w->tam;
  y = y % w->tam;
  if (x < 0)
    x += w->tam;
  if (y < 0)
    y += w->tam;

  return *(w->w1 + w->tam*x + y);
  
}

// La función vivas cuentas las vecinas vivas de la célula a la que
// apunta el puntero t, y devuelve dicho valor.

int vivas(struct gol *w,int i, int j)
{
  return vecina(w, i-1, j-1) +
         vecina(w, i,   j-1) +
         vecina(w, i+1, j-1) +
         vecina(w, i-1, j)   +
         vecina(w, i+1, j)   +
         vecina(w, i-1, j+1) +
         vecina(w, i,   j+1) +
         vecina(w, i+1, j+1);
}

struct gol *gol_alloc(int tam)
{
  struct gol *w;

  w = (struct gol *)malloc(sizeof(struct gol));
  if (!w)
    return NULL;
  w->w1 = (int *)malloc(tam*tam*sizeof(int));
  if (!w->w1)
    return NULL;
  w->w2 = (int *)malloc(tam*tam*sizeof(int));
  if (!w->w2)
    return NULL;
  w-> tam = tam - 1;

  return w;
}

void gol_free(struct gol *w)
{
  free(w->w1);
  free(w->w2);
  free(w);
}

void gol_init(struct world *w)
{
  memset(w->w1, 0, w->tam*w->tam*sizeof(int));
  memset(w->w2, 0, w->tam*w->tam*sizeof(int));
}
