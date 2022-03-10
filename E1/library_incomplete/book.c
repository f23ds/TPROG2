
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

/* START [defines] */
#define MAX_TITLE_LEN 128
#define MAX_AUTHOR_LEN 64
#define MAX_ISBN_LEN 32
/* END [defines] */

/* START [_Book] */
struct _Book {
  char title[MAX_TITLE_LEN];
  char author[MAX_AUTHOR_LEN];
  char isbn[MAX_ISBN_LEN];
  int num_copies;
};
/* END [_Book] */

/*------------------------------------------------------------------------*/
/* START [book_new] */
Book *book_new(const char *descr) {
  int i;
  Book *b = NULL;
  char buff[64];
  
  if (descr==NULL) return NULL;

  b = (Book *)malloc(sizeof(Book));
  if (b==NULL) return NULL;

  i = sscanf(descr, "%s %s %s %s", b->author, b->title, b->isbn, buff);
  if (i != 4) {
    free(b);
    return NULL;
  }
  
  b->num_copies = atoi(buff);

  return b;
}
/* END [book_new] */

/*------------------------------------------------------------------------*/
/* START [book_free] */
void book_free(Book *b) {
  free (b);
}
/* END [book_free] */

/*------------------------------------------------------------------------*/
/* START [book_getTitle] */
const char *book_getTitle(const Book *b) {
  if (b==NULL) return NULL;  
  return b->title;
} 
/* END [book_getTitle] */

/*------------------------------------------------------------------------*/
/* START [book_getAuthor] */
const char *book_getAuthor(const Book *b) {
  if (b==NULL) return NULL;
  return b->author;
}
/* END [book_getAuthor] */

/*------------------------------------------------------------------------*/
/* START [book_getISBN] */
const char *book_getISBN(const Book *b) {
  if (b==NULL) return NULL;
  return b->isbn;
}
/* END [book_getISBN] */

/*------------------------------------------------------------------------*/
/* START [book_getNumCopies] */
int book_getNumCopies(const Book *b) {
  if (b==NULL) return -1;
  return b->num_copies;
}
/* END [book_getNumCopies] */

/*------------------------------------------------------------------------*/
/* START [book_setNumCopies] */
Status book_setNumCopies(Book *b, const int n) {
  if (b==NULL) return ERROR;
  if (n<0) return ERROR;
  
  b->num_copies = n;
  return OK;
}
/* END [book_setNumCopies] */

/*------------------------------------------------------------------------*/
/* START [book_print] */
int book_print(FILE * pf, const Book *plib) {
  if (plib==NULL || pf==NULL) return ERROR;
  
  return fprintf(pf,
		 "Title: %s\nAuthor: %s\nISBN: %s\nNum_copies: %d\n",
		 plib->title, plib->author, plib->isbn, plib->num_copies);
}
/* START [book_print] */

/*------------------------------------------------------------------------*/
/* START [book_cmp] */
int book_cmp(const Book *b1, const Book *b2) {
    if (b1==NULL || b2==NULL) return 0;
    return (strcmp(b1->isbn, b2->isbn));   
}
/* END [book_cmp] */







