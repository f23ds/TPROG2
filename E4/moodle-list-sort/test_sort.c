#include "list.h"
#include "list_sort.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// private
Boolean check_order(int *array, int n_elem);

//--------------------------------------------------------------------------
Boolean check_order(int *array, int n_elem) {
  int i;

  for (i = 0; i < n_elem - 1; i++) {
    if (array[i] < array[i + 1]) {
      return FALSE;
    }
  }
  return TRUE;
}

void test_pushSorted() {
  Status st = OK;
  int i;
  int ai[] = {3, 5, 7, 6, 1, 0};
  char ac[] = {'z', 'A', 'a', 'b', 'd'};
  char *as[] = {"the", "snow", "is", "white"};
  // char *as[] = {"BB", "EE", "CC", "AA"};

  List *pl = NULL;

  printf("Testing list_pushSorted\n");
  printf("TEST 1: insert ints in order\n");
  pl = list_new();
  if (!pl) {
    printf("Error allocating list\n");
  } else {
    for (i = 0; i < 6 && st == OK; i++) {
      st = list_pushSorted(pl, ai + i, int_cmp);
    }
    if (st == OK) {
      list_print(stdout, pl, int_print);
      printf("\n");
    } else {
      printf("Error adding elements to list\n");
    }
    list_free(pl);
  }

  printf("\nTEST 2: insert chars in order\n");
  st = OK;
  pl = list_new();
  if (!pl) {
    printf("Error allocating list\n");
  } else {
    for (i = 0; i < 5 && st == OK; i++) {
      st = list_pushSorted(pl, ac + i, char_cmp);
    }
    if (st == OK) {
      list_print(stdout, pl, char_print);
      printf("\n");
    } else {
      printf("Error adding elements to list\n");
    }
    list_free(pl);
  }

  printf("\nTEST 3: insert strings in order\n");
  st = OK;
  pl = list_new();
  if (!pl) {
    printf("Error allocating list\n");
  } else {
    for (i = 0; i < 4 && st == OK; i++) {
      st = list_pushSorted(pl, as + i, string_cmp);
    }
    if (st == OK) {
      list_print(stdout, pl, string_print);
      printf("\n");
    } else {
      printf("Error adding elements to list\n");
    }
    list_free(pl);
  }
}

void test_sort_int_array(int n_elem) {
  int *array = NULL;
  int i;

  printf("TEST 4: test sort_int_array\n");
  srand(time(NULL));

  array = (int *)malloc(n_elem * sizeof(int));
  if (array == NULL) {
    fprintf(stderr, "Error allocating memory\n");
    return;
  }

  for (i = 0; i < n_elem; i++) {
    array[i] = rand() % 100;
  }

  printf("Original array: ");
  for (i = 0; i < n_elem; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  if (sort_int_array(array, n_elem) == ERROR) {
    fprintf(stdout, "Error sorting the array\n");
  } else {
    printf("Sorted array: ");
    for (i = 0; i < n_elem; i++) {
      printf("%d ", array[i]);
    }
    if (check_order(array, n_elem)) {
      fprintf(stdout, "\nArray correctly sorted\n");
    } else {
      fprintf(stdout, "\nArray incorrectly sorted\n");
    }
  }

  free(array);
}

//--------------------------------------------------------------------------
int main(int argc, char *argv[]) {
  int n_elem;

  // With no arguments, test list_pushSorted with various types
  if (argc == 1) {
    test_pushSorted();
    return EXIT_SUCCESS;
  }

  // With one (int) argument, generate random array with size = arg
  if (argc < 2 || (n_elem = atoi(argv[1])) < 0) {
    fprintf(stderr, "Usage: %s <Size of test>\n", argv[0]);
    return 1;
  }
  test_sort_int_array(n_elem);
}
