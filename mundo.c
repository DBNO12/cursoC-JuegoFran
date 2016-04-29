#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mundo.h"

int itera(int *t, int *s, int n, int m, int l)
{
    int i, j, vecinas, cell;

// Cambiamos el array - tablero según las reglas de nuestro juego
// a través de un puntero
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++, s++) {
       vecinas = vivas(t,n,i,j);
       cell  = vecina(t,n,i,j);
       if ((cell == 1) && (vecinas >= 2) && 
           (vecinas <= 3))
          *s = 1;
        else if (cell == 1)
          *s = 0;
        else if (vecinas == 3)
          *s = 1;
        else
          *s = 0; 
    }

// Devolvemos los punteros al inicio de las matrices - tableros e
// imprimimos el estado final después de la iteración
  s -= (n*n);
  printf("Este es el paso número %d\n", l);
  print(t,n);

  // Limitamos las iteraciones
  if (l == m) {
    printf("¡¡Y hasta aquí el juego!!\n");
    exit(0);
  }

// Introducimos una pequeña pausa
  int x;
  printf("Escribe un número y presiona enter para continuar: ");
  scanf("%d", &x);
  printf("\n");

// Llamada recursiva  
  return itera(s,t,n,m,l+1);
}

int print(int *t, int n)
{
  int i;
  int j;

  for (i = 0; i < n; i++) { 
    for (j = 0; j < n; j++, t++)
        printf(" %d ", *t);
      printf("\n"); 
}

  printf("\n");
  
  return 0;
}

int vecina(int *t, int n, int x, int y)
{
  // Calculamos modulos
  x = x % n;
  y = y % n;
  if (x < 0)
    x += n;
  if (y < 0)
    y += n;

  return *(t + n*x + y);
  
}

// La función vivas cuentas las vecinas vivas de la célula a la que
// apunta el puntero t, y devuelve dicho valor.

int vivas(int *t,int n,int i, int j)
{
  return vecina(t, n, i-1, j-1) +
         vecina(t, n, i,   j-1) +
         vecina(t, n, i+1, j-1) +
         vecina(t, n, i-1, j)   +
         vecina(t, n, i+1, j)   +
         vecina(t, n, i-1, j+1) +
         vecina(t, n, i,   j+1) +
         vecina(t, n, i+1, j+1);
}
