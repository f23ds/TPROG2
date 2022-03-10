#ifndef BOOK_H
#define BOOK_H

#include "types.h"
#include <stdio.h>

/* START [Book] */
typedef struct _Book Book;
/* END [Book] */

Book *book_new(const char *descr);
void book_free(Book *b);

const char *book_getTitle(const Book *b);
const char *book_getAuthor(const Book *b);
const char *book_getISBN(const Book *b);
int book_getNumCopies(const Book *b);

Status book_setNumCopies(Book *b, const int n);

int book_print(FILE *f, const Book *b);
int book_cmp(const Book *b1, const Book *b2);

#endif /* BOOK_H */
