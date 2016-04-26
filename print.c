#include <stdio.h>

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
