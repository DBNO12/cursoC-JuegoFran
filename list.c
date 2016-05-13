#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list_cell *init_list(struct list_cell *cell)
{
  INIT_LIST_HEAD(cell);
  return cell;
}


void add_list(struct list_cell *current, struct list_cell *cell)
{
  list_add(current,cell);
}
