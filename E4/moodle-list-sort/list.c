/*--------------------------------------------------------------------------
  Sort module.
  --------------------------------------------------------------------------*/

#include "list.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Private function that creates a new node.
 *
 * Allocates memory and sets the info and next pointers to NULL. Note that there
 * is no Node destructor, the destruction of a Node must be done by directly
 * calling the free function of the standard library.
 *
 * @return Returns the address of the new node, or NULL in case of error.
 */
Node *node_new() {
  Node *pn = NULL;

  pn = (Node *)malloc(sizeof(Node));
  if (!pn) {
    return NULL;
  }

  pn->info = NULL;
  pn->next = NULL;

  return pn;
}

/**
 * @brief Private function that creates a new List (that should be kept sorted).
 *
 * Allocates memory for the new List.
 *
 * @return Returns the address of the new list, or NULL in case of error.
 */

List *list_new() {
  List *pl = NULL;

  pl = (List *)malloc(sizeof(List));
  if (pl == NULL) {
    return NULL;
  }

  pl->first = NULL;

  return pl;
}

/**
 * @brief Private function that checks if a List is empty.
 *
 * Note that the return value is TRUE for a NULL List.
 *
 * @param pl Pointer to the List.
 *
 * @return Boolean value TRUE if the list is empty or NULL, Boolean value FALSE
 * otherwise.
 */
Boolean list_isEmpty(const List *pl) {
  if (pl == NULL) {
    return TRUE;
  }

  if (pl->first == NULL) {
    return TRUE;
  }

  return FALSE;
}

/**
 * @brief Private function that pops the front element from a sorted List (the
 * maximum).
 *
 * Extracts the front element from the List, returning it.
 *
 * @param pl Pointer to the List.
 *
 * @return Extracted element, NULL if the List is empty or NULL.
 */

void *list_popFront(List *pl) {
  Node *pn = NULL;
  void *pe = NULL;

  if (pl == NULL || list_isEmpty(pl) == TRUE) {
    return NULL;
  }

  pn = pl->first;
  pe = pn->info; /* Equivalently: pe = pl->first->info */
  pl->first = pn->next;

  free(pn);

  return pe;
}

/**
 * @brief Public function that pops the back element from a sorted List (the
 * minimum).
 *
 * Extracts the back element from the List, returning it.
 *
 * Note that it is necessary to traverse the list in order to obtain the
 * extract position, so this operation is linear in the number of List elements.
 *
 * @param pl Pointer to the List.
 *
 * @return Extracted element, NULL if the List is empty or NULL.
 */

void *list_popBack(List *pl) {
  Node *pn = NULL;
  void *pe = NULL;

  if (pl == NULL || list_isEmpty(pl) == TRUE) {
    return NULL;
  }

  /* Case 1: List with one single element - extract the first element: */
  if (pl->first->next == NULL) {
    pe = pl->first->info;
    free(pl->first);
    pl->first = NULL;

    return pe;
  }

  /* Case 2: List with more than one element - traverse the List
    and extract: */
  pn = pl->first;
  while (pn->next->next != NULL) {
    pn = pn->next;
  }

  pe = pn->next->info;
  free(pn->next);
  pn->next = NULL;

  return pe;
}

/**
 * @brief Private function that frees a List.
 *
 * Frees the memory allocated for the List.
 *
 * @param pl Pointer to the List.
 */
void list_free(List *pl) {
  if (pl == NULL) {
    return;
  }

  while (list_isEmpty(pl) == FALSE) {
    list_popFront(pl);
  }

  free(pl);
}

int list_print(FILE *fp, const List *pl, elem_print_fn print_elem) {
  Node *pn = NULL;
  int return_value = 0;
  int val = 0;

  if (pl == NULL || fp == NULL) {
    return -1;
  }

  pn = pl->first;
  while (pn != NULL) {
    val = print_elem(fp, pn->info);
    if (val < 0) {
      return val;
    }
    fprintf(fp, " ");
    return_value += val + 1;
    pn = pn->next;
  }

  return return_value;
}
