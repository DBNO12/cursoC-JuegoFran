#include <stdio.h>

int vecina(int *t, int i, int j,int n, int x, int y)
{
  t += (y-j)*n + x - i;
  printf("(%d,%d,%d)\n",x,y,*t);

  return *t;
}
