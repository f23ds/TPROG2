/**
 * @file sort.h
 * @author Programming II Teaching Team
 * @date 5 Abr 2020
 * @brief Public interface for sorting using a list.
 */

#ifndef LIST_H
#define LIST_H

#include "elements.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Public function that sorts an array of integers.
 *
 * Modifies the array to sort it in decreasing order
 *
 * @param array Array of integers to be sorted.
 * @param n_elem Size of the array.

 *
 * @return Status value OK if the array could be sorted, Status value ERROR
 * otherwise.
 */

/**
 * Node definition:
 * The node's info field is a pointer to void, so that the list can contain
 * generic elements.
 */

struct _Node {
  void *info;
  struct _Node *next;
};

typedef struct _Node Node;

/**
 * List definition:
 * It contains a pointer to the first node.
 */
struct _List {
  Node *first;
};

typedef struct _List List;

/**
 * @brief Private function that creates a new node.
 *
 * Allocates memory and sets the info and next pointers to NULL. Note that there
 * is no Node destructor, the destruction of a Node must be done by directly
 * calling the free function of the standard library.
 *
 * @return Returns the address of the new node, or NULL in case of error.
 */
Node *node_new();

/**
 * @brief Private function that creates a new List (that should be kept
 * sorted).
 *
 * Allocates memory for the new List.
 *
 * @return Returns the address of the new list, or NULL in case of error.
 */

List *list_new();

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
Boolean list_isEmpty(const List *pl);

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

void *list_popFront(List *pl);

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

void *list_popBack(List *pl);

/**
 * @brief Private function that frees a List.
 *
 * Frees the memory allocated for the List.
 *
 * @param pl Pointer to the List.
 */

void list_free(List *pl);

/**
 * @brief Public function that prints a list using a print function for the
 * elements of the list.
 *
 *
 * @param pl Pointer to the List.
 */

int list_print(FILE *pf, const List *pl, elem_print_fn print_elem);

#endif /* LIST_H */
