#include <stdio.h>

int itera(int *t, int *s, int n)
{
  int i, j;

// Cambiamos el array - tablero según las reglas de nuestro juego
// a través de un puntero
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++, t++, s++)
       if ((*t == 1) && (vivas(t,n,i,j) >= 2) && 
           (vivas(t,n,i,j) <= 3))
          *s = 1;
        else if (*t == 1)
          *s = 0;
        else if (vivas(t,n,i,j) == 3)
          *s = 1;
        else
          *s = 0; 

// Devolvemos los punteros al inicio de las matrices - tableros e
// imprimimos el estado final después de la iteración
  s -= (n*n);
  t -= (n*n);
  print(s,n);

// Introducimos una pequeña pausa
  int x;
  printf("Escribe un número y presiona enter para continuar: ");
  scanf("%d", &x);
  printf("\n");

// Llamada recursiva  
  return itera(s,t,n);
}
