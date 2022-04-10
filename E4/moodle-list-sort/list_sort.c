#include "elements.h"
#include "list.h"
#include "types.h"
#include <stdlib.h>

/**
 * @brief Public function that pushes an element into a sorted List.
 *
 * Inserts into the corresponding position the element received as argument.
 *
 * @param pl Pointer to the List.
 * @param e Element to be inserted into the List.
 * @param f Pointer to the compare function.

 *
 * @return Status value OK if the insertion could be done, Status value ERROR
 * otherwise.
 */
Status list_pushSorted(List *pl, const void *e, elem_cmp_fn elem_cmp)
{
  Node *pn = NULL, *new = NULL, *pn_aux = NULL;

  if (!pl || !e || !elem_cmp)
    return ERROR;

  pn = node_new();
  new = node_new();

  new->info = (void *)e;
  new->next = NULL;

  pn = pl->first;

  if (list_isEmpty(pl) == TRUE) {
    pl->first = new;

    return OK;
  }

  while (pn->next != NULL && elem_cmp(pn->next->info, new->info) < 0)
  {
    pn_aux = pn;
    pn = pn->next;
  }

  new->next = pn;
  pn_aux->next = new;

  return OK;
}

/**
 * @brief Public function that sorts an integer array.
 *
 *
 * @param array An integer array.
 * @param n_elem Size of array

 *
 * @return Status value OK if array sorted without problems, Status value ERROR
 * otherwise. The array is sorted in decreasing order upon return.
 */

Status sort_int_array(int *array, int n_elem)
{
  List *pl = NULL;
  void *e = NULL;
  Status st = OK;
  int i;

  if (!array)
    return ERROR;

  /* Creamos una lista para introducir los valores */
  pl = list_new();

  for (i = 0; i < n_elem && st == OK; i++) {
    e = &array[i];
    st = list_pushSorted(pl, e, int_cmp);
  }

  if (st == ERROR) {
    free(pl);
    return ERROR;
  }

  return ERROR;
}