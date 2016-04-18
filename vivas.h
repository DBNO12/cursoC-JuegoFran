// La función vivas(const struct casilla *t) cuentas las vecinas 
// vivas de la célula a la que apunta el puntero t, y devuelve
// dicho valor.

// Las diferentes guardas se identifican con diferentes posiciones
// de las células apuntadas por el puntero, de manera que definimos
// el conteo para que el mundo sera cerrado (como una especie de esfera).
int vivas(struct casilla *t,int n)
{
  // Guardamos la posición de t
  int B = t->x;
  int Y = t->y;
//
  const struct casilla *AX;
  const struct casilla *AY;
  const struct casilla *AZ;
  const struct casilla *BX;
  // BY = t
  const struct casilla *BZ;
  const struct casilla *CX;
  const struct casilla *CY;
  const struct casilla *CZ;
//
  if ((B == 0) && (Y == 0))
    { BZ = ++t;
      t += (n-2);
      BX = t++;
      CY = t++;
      CZ = t++;
      t += (n-3);
      CX = t++;
      t += ((n-3)*n);
      AY = t++;
      AZ = t++;
      t += (n-3);
      AX = t; }
  else if ((B == (n-1)) && (Y == 0))
    { t--;
      BX = t--;
      t -= (n-3);
      BZ = t++;
      t += (n-1);
      CZ = t++;
      t += (n-3);
      CX = t++;
      CY = t++;
      t += ((n-3)*n);
      AZ = t++;
      t += (n-3);
      AX = t++;
      AY = t; }
  else if ((B == 0) && (Y == (n-1)))
    { t -= ((n-1)*n);
      CY = t++;
      CZ = t++;
      t += (n-3);
      CX = t++;
      t += ((n-3)*n);
      AY = t++;
      AZ = t++;
      t += (n-3);
      AX = t++;
      t++;
      BZ = t++;
      t += (n-3);
      BX = t;}
  else if ((B == (n-1)) && (Y == (n-1)))
    { t--;
      BX = t--;
      t -= (n-3);
      BZ = t--;
      AY = t--;
      AX = t--;
      t -= (n-3);
      AZ = t--;
      t -= ((n-3)*n);
      CY = t--;
      CX = t--;
      t -= (n-3);
      CZ = t; }
  else if (B == 0)
    { t -= n;
      AY = t++;
      AZ = t++;
      t += (n-3);
      AX = t++;
      t++;
      BZ = t++;
      t += (n-3);
      BX = t++;
      CY = t++;
      CZ = t++;
      t += (n-3);
      CX = t; }
  else if (B == (n-1))
    { t += n;
      CY = t--;
      CX = t--;
      t -= (n-3);
      CZ = t--;
      t--;
      BX = t--;
      t -= (n-3);
      BZ = t--;
      AY = t--;
      AX = t--;
      t -= (n-3);
      AZ = t; }
  else if (Y == 0)
    { t--;
      AY = t++;
      t++;
      CY = t++;
      t += (n-3);
      AZ = t++;
      BZ = t++;
      CZ = t++;
      t += ((n-3)*n+n-3);
      AX = t++;
      BX = t++;
      CX = t; }
  else if (Y == (n-1))
    { t++;
      CY = t--;
      t--;
      AY = t--;
      t -= (n-3);
      CX = t--;
      BX = t--;
      AX = t--;
      t -= ((n-3)*n+n-3);
      CZ = t;
      BZ = t;
      AZ = t; }
  else
    { t -= (n+1);
      AX = t++;
      BX = t++;
      CX = t++;
      t += (n-3);
      AY = t++;
      t++;
      CY = t++;
      t += (n-3);
      AZ = t++;
      BZ = t++;
      CZ = t; };
//
  return AX->cel + AY->cel + AZ->cel + BX->cel + BZ->cel
         + CX-> cel + CY->cel + CZ->cel; 
}
