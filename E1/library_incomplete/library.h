#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "types.h"
#include <stdio.h>

/* START [Library] */
typedef struct _Library Library;
/* END [Library] */

Library *library_new();
void library_free(Library *l);

Boolean library_isEmpty(const Library *l);
Boolean library_hasBook(const Library *l, const char *isbn);

Status library_addBook(Library *l, const char *descr);
Status library_removeBook(Library *l, const char *isbn);

int library_print(FILE *f, const Library *l);

#endif /* LIBRARY_H */

