int itera(int *t, int *s, int n)
{
  int i, j;

  for (i < 0; i < n; t++, s++)
    for (j < 0; j < n; t++, s++)
      { if ((*t == 1) && (vivas(t,n,i,j) >= 2) && 
            (vivas(t,n,i,j) <= 3))
          *s = 1;
        else if (*t = 1)
          *s = 0;
        else if (vivas(t,n,i,j) == 3)
          *s = 1;
        else
          *s = 0; }

  print(s,n);
  
  return itera(s,t,n);
}
