#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mundo.h"
#include "list.h"

struct list_cell {
  int cell_x;
  int cell_y;
  struct list_head list;
};

struct gol {
  int *w;
  int tam;
  struct list_cell alive;
  struct list_cell to_kill;
  struct list_cell to_revive;
};

int itera(struct gol *w)
{
  int i, j, k, l, vecinas, cell;
  
  struct list_cell *pos;
  list_for_each_entry(pos, &(w->alive.list), w->alive.list) 
    for (i = -1; i < 1; i++)
      for (j = -1; j < 1; j++) {
        cell = vecina(w, pos->cell_x + i, pos->cell_y + j);
        vecinas = vivas(w, pos->cell_x + i, pos->cell_y + j);
        if (cell && ((vecinas < 2) || (vecinas > 3))) {
          struct list_cell *kill;
          kill->cell_x = pos->cell_x + i;
          kill->cell_y = pos->cell_y + j;
          list_add(&(kill->list), &(w->to_kill.list));
        }
        else if  (vecinas == 3) {
          struct list_cell *revive;
          revive->cell_x = pos->cell_x + i;
          revive->cell_y = pos->cell_y + j;
          list_add(&(revive.list), &(w->to_revive.list));
        }
      }

  return 0;
}

int print(struct gol *w)
{
  int i;
  int j;
  int x;

  printf("+");
  for (i = 0; i < w->tam; i++)
    printf("-");
  printf("+\n");
  for (i = 0; i < w->tam; i++) {
    printf("|");
    for (j = 0; j < w->tam; j++) {
      x = vecina(w,i,j);
      if (x)
        printf("X");
      else
        printf(" ");
    }
      printf("|\n"); 
  }
  printf("+");
  for (i = 0; i < w->tam; i++)
    printf("-");
  printf("+\n\n");
  
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

  return *(w->w + x*w->tam + y);
  
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
  w->w = (int *)malloc(tam*tam*sizeof(int));
  if (!w->w)
    return NULL;

  w->tam = tam;

  return w;
}

void gol_free(struct gol *w)
{
  free(w->w);
  free(w);
}

void gol_init(struct gol *w)
{
  memset(w->w, 0, w->tam*w->tam*sizeof(int));
  INIT_LIST_HEAD(&w->alive.list);
  INIT_LIST_HEAD(&w->to_kill.list);
  INIT_LIST_HEAD(&w->to_revive.list);
  
  *(w->w + 1) = 1;
  *(w->w + w->tam + 2) = 1;
  *(w->w + 2*w->tam) = 1;
  *(w->w + 2*w->tam + 1) = 1;
  *(w->w + 2*w->tam + 2) = 1;
}

void set_cell(struct gol *w, int i, int j, int x)
{
  *(w->w + i*w->tam + j) = x;
}

int list_kill(struct gol *w)
{
  struct list_cell *pos;
  list_for_each_entry(pos,&(w->to_kill.list), w->to_kill.list) {
    set_cell(w, pos->cell_x, pos->cell_y, 0);
    list_del(pos);
  }

  return 0;
}

int list_revive(struct gol *w)
{
  struct list_cell *pos;

  list_for_each_entry(pos, &(w->to_revive.list), w->to_revive.list) {
    set_cell(w, pos->cell_x, pos->cell_y, 1);
    list_del(pos);
  }

  return 0;
}

int init_alive(struct gol *w)
{
  int i;
  int j;
  int cell;
  
  for (i = 0; i < w->tam; i++)
    for (j = 0; j < w->tam; j++) {
      cell = vecina(w,i,j);
      if (num) {
        struct list_cell *new;
        new->cell_x = i;
        new->cell_y = j;
        list_add(&(new->list),w->alive.list);
      }
    }
  
  return 0;
}

