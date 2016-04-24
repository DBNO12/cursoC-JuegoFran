#include <stdio.h>

int itera(int *t, int *s, int n)
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; t++, s++)
       if ((*t == 1) && (vivas(t,n,i,j) >= 2) && 
           (vivas(t,n,i,j) <= 3))
          *s = 1;
        else if (*t = 1)
          *s = 0;
        else if (vivas(t,n,i,j) == 3)
          *s = 1;
        else
          *s = 0; 

  t -= (n*n);
  s -= (n*n);
  print(s,n);

  int x;
  scanf("Escribe un número y presiona enter para continuar: ", &x);
  
  return itera(s,t,n);
}
