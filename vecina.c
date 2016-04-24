#include <stdio.h>

int vecina(int *t, int i, int j,int n, int x, int y)
{
  
  t += (x-i)*n + y - j;

  return *t;
  
}
