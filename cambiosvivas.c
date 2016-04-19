// La función vivas(const struct casilla *t) cuentas las vecinas 
// vivas de la célula a la que apunta el puntero t, y devuelve
// dicho valor.

// Las diferentes guardas se identifican con diferentes posiciones
// de las células apuntadas por el puntero, de manera que definimos
// el conteo para que el mundo sera cerrado (como una especie de 
// esfera).

int vivas(int p,int n,int i, int j)
{
  int s = p[mod(i-1,n)][mod(j-1,n)] +
          p[mod(i,n)][mod((j-1),n)] +
          p[mod(i+1,n)][mod(j-1,n)] +
          p[mod(i-1,n)][mod(j,n)] +
          p[mod(i,n)][mod(j,n)] +
          p[mod(i+1,n)][mod(j,n)] +
          p[mod(i-1,n)][mod(j+1,n)] +
          p[mod(i,n)][mod(j+1,n)] +
          p[mod(i+1,n)][mod(j+1,n)]

  return s;
}
