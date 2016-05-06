struct gol;
int itera(struct gol *w);
int print(struct gol *w);
int vecina(struct gol *w, int x, int y);
int vivas(struct gol *w,int i, int j);
struct gol *gol_alloc(int tam);
void gol_free(struct gol *w);
void gol_init(struct gol *w);
void set_cell(struct gol *w, int i, int j, int x);
