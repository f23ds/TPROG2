#ifndef _LIST_SORT_H
#define _LIST_SORT_H
#include "elements.h"
#include "list.h"
#include "types.h"

Status list_pushSorted(List *pl, const void *e, elem_cmp_fn elem_cmp);
Status sort_int_array(int *array, int n_elem);

#endif