// Definimos la funcion que nos permitirá imprimir el tablero
// después de cada iteración

int print(struct casilla  *t, int n)
{
  int i;
  int j;
  int r;
  
  for (i = 0, j = 0, r = 0; r < (n*n); r++, j++, t++)
    if ((j == (n-1)) && (t->cel == 1))
      { printf("X\n");
        j = -1;
        i++; }
    else if ( j == (n-1) )
      { printf(" \n");
        j = -1;
        i++; }
    else if ( t->cel == 1 )
      printf("X");
    else 
     printf(" ");
  printf("\n");

  return 0;
}
