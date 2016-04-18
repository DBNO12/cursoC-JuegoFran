// Definimos la función que nos permite realizar las iteraciones

int itera(struct casilla *t,int n)
{  
  struct casilla q[n][n];
  int i;
  int j;
  int r;
     
  for (i = 0, j = 0, r = 0; r < (n*n); r++, j++, t++)
    if ((j == 9) && (t->cel == 0) && (vivas(t,n) == 3))
      { q[i][j].x = 9;
        q[i][j].y = i;
        q[i][j].cel = 1;
        j = -1;
        i++; }
    else if ((j == 9) && (t->cel == 1) && (vivas(t,n) >= 2)
         && (vivas(t,n) <= 3))
      { q[i][j].x = 9;
        q[i][j].y = i;
        q[i][j].cel = 1;
        j = -1;
        i++; }
    else if ( j == 9 )
      { q[i][j].x = 9;
        q[i][j].y = i;
        q[i][j].cel = 0;
        j = -1;
        i++; }
    else if ((t->cel == 0) && (vivas(t,n) == 3))
      { q[i][j].x = 9;
        q[i][j].y = i;
        q[i][j].cel = 1; }
    else if ((t->cel == 1) && (vivas(t,n) >= 2) &&
             (vivas(t,n) <= 3))
      { q[i][j].x = 9;
        q[i][j].y = i;
        q[i][j].cel = 1; }
    else
      { q[i][j].x = 9;
        q[i][j].y = i;
        q[i][j].cel = 0; }

  int c;
  printf("¡Escribe un número y presiona enter para continuar!\n");
  scanf("%d\n",&c);

  struct casilla *s = q;
  print(s,n);
  
  return itera(s,n);
}