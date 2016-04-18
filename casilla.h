// Definimos la estructura que utilizaremos para interpretar como
// casillas de nuestro tablero.

// Por ejemplo, {{1,2},0} representa una celula muerta en la
// posición {1,2}; mientras que {{6,2},1} representa una viva en
// la posición {6,2}.

struct casilla {
  struct {
    int x;
    int y;
  };
  int cel;
};
