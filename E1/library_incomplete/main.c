/* 
 * File:   main.c
 * Author: eserrano
 *
 * Created on 25 de enero de 2018, 12:23
*/

#include <stdio.h>
#include <stdlib.h>

#include "library.h"

int main(int argc, char** argv) {
  Library *l = NULL;
  Status st = OK;
  char *tag = NULL;
  
  // Create new library:
  l = library_new();
  if (!l) {
    return EXIT_FAILURE;
  }	
  
  // Create book and add it to the library:
  tag = "Cervantes El_ingenioso_hidalgo_don_quijote 999 5";
  st = library_addBook(l, tag);
  if (st == ERROR) {
    library_free(l);
    return EXIT_FAILURE;
  }

  // Create a second book and add it to the library:
  tag = "Cartwright_Mark Fourier_methods 996 1";
  st = library_addBook (l, tag);
  if (st ==ERROR) {
    library_free (l);
    return EXIT_FAILURE;
  }    

  puts("\n(1) Library print (initial):\n");
  library_print(stdout, l);
  
  // Increase the number of copies of first book (new insertion):
  tag = "Cervantes El_ingenioso_hidalgo_don_quijote 999 -15";
  st = library_addBook(l, tag);
  
  puts("\n(2) Library print (after increasing number of copies of first book):\n");
  library_print (stdout, l);
  
  // Remove first book:
  st = library_removeBook (l, "999");
  
  puts("\n(3) Library print (after removing first book):\n");
  library_print (stdout, l);

  library_free(l);
  return EXIT_SUCCESS;
}

