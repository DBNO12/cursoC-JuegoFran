#include <stdio.h>

// La función vivas cuentas las vecinas vivas de la célula a la que
// apunta el puntero t, y devuelve dicho valor.

int vivas(int *t,int n,int i, int j)
{
  int a = (n + (i-1) % n) % n;
  int b = (n + (i+1) % n) % n;
  int c = (n + (j-1) % n) % n;
  int d = (n + (j+1) % n) % n;

  int s = vecina(t,i,j,n,a,c) +
          vecina(t,i,j,n,a,j) +
          vecina(t,i,j,n,a,d) +
          vecina(t,i,j,n,i,c) + 
          vecina(t,i,j,n,i,d) +
          vecina(t,i,j,n,b,c) +
          vecina(t,i,j,n,b,j) +
          vecina(t,i,j,n,b,d);

  return s;
}
