/* NOMBRE: Fabio Desio Suárez
PRÁCTICA 1: TAD
ASIGNATURA: PROGRAMACIÓN II
FECHA: 27/02/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"

/* START [defines] */
#define MAX_BOOKS 1064
/* END [defines] */

/* START [_Library] */
struct _Library
{
  Book *catalog[MAX_BOOKS];
  int num_books;
};
/* END  [_Library] */

/*------------------------------------------------------------------------*/
/* Private functions                                                      */
/*------------------------------------------------------------------------*/
Boolean _library_isFull(const Library *p);
int _library_findBookByISBN(const Library *l, const char *isbn);

/*------------------------------------------------------------------------*/
/* START [_library_isFull] */
Boolean _library_isFull(const Library *p)
{
  if (p == NULL)
    return TRUE;
  if (p->num_books == MAX_BOOKS)
    return TRUE;
  return FALSE;
}
/* END [_library_isFull] */

/*------------------------------------------------------------------------*/
/* START [_library_findBookByISBN] */
int _library_findBookByISBN(const Library *l, const char *isbn)
{
  int i;
  const char *buff;
  Boolean bool = FALSE;

  if (!l || !isbn || library_isEmpty(l) == TRUE)
    return -1;

  for (i = 0; i < l->num_books && bool == FALSE; i++)
  {
    buff = book_getISBN(l->catalog[i]);
    if (strcmp(buff, isbn) == 0)
      bool = TRUE;
  }

  if (bool == TRUE)
    return (i - 1);
  else
    return -1;
}
/* END [_library_findBookByISBN] */

/*------------------------------------------------------------------------*/
/* Public functions                                                       */
/*------------------------------------------------------------------------*/
/* START [library_new] */
Library *library_new()
{
  Library *l = NULL;
  int i;

  l = (Library *)malloc(sizeof(Library));
  if (l == NULL)
    return NULL;

  l->num_books = 0;

  for (i = 0; i < MAX_BOOKS; i++)
    l->catalog[i] = NULL;

  return l;
}
/* END [library_new] */

/*------------------------------------------------------------------------*/
/* START [library_free] */
void library_free(Library *l)
{
  int i;
  if (l == NULL)
    return;

  for (i = 0; i < l->num_books; i++)
  {
    book_free(l->catalog[i]);
  }

  free(l);
}
/* END [library_free] */

/*------------------------------------------------------------------------*/
/* START [library_isEmpty] */
Boolean library_isEmpty(const Library *l)
{
  if (l == NULL)
    return TRUE;
  if (l->num_books == 0)
    return TRUE;
  return FALSE;
}
/* END [library_isEmpty] */

/*------------------------------------------------------------------------*/
/* START [library_hasBook] */
Boolean library_hasBook(const Library *l, const char *isbn)
{
  return _library_findBookByISBN(l, isbn) > -1 ? TRUE : FALSE;
}
/* END [library_hasBook] */

/*------------------------------------------------------------------------*/
/* START [library_addBook] */
Status library_addBook(Library *l, const char *descr)
{
  Book *b = NULL;
  int pos;
  Status status;

  // Comprobamos que los punteros no son nulos
  if (l == NULL || descr == NULL)
    return ERROR;

  // Creamos un nuevo libro para añadir a la librería
  b = book_new(descr);

  if (b == NULL)
    return ERROR;

  if (book_getNumCopies(b) <= 0)
  {
    book_free(b);
    return ERROR;
  }

  pos = _library_findBookByISBN(l, book_getISBN(b));

  // Si el libro ya está en la librería, se incrementa en uno el número de copias
  if (pos != -1)
  {
    status = book_setNumCopies(l->catalog[pos], book_getNumCopies(l->catalog[pos]) + book_getNumCopies(b));

    if (status == ERROR)
    {
      book_free(b);
      return ERROR;
    }

    book_free(b);
  }
  else
  { // Si no, se añade a la librería
    if (_library_isFull(l))
    {
      book_free(b);
      return ERROR;
    }

    l->catalog[l->num_books] = b;
    l->num_books++;
  }

  return OK;
}
/* END [library_addBook] */

/*------------------------------------------------------------------------*/
/* START [library_removeBook] */
Status library_removeBook(Library *l, const char *isbn)
{
  Boolean b;
  int pos, i;
  // Comprobamos los punteros
  if (l == NULL || isbn == NULL)
    return ERROR;

  // Comprobamos que el libro está en la librería
  b = library_hasBook(l, isbn);
  if (!b)
    return ERROR;

  pos = _library_findBookByISBN(l, isbn);

  book_free(l->catalog[pos]);

  // Recorremos los libros restantes y eliminamos el libro en cuestión
  for (i = pos; i < l->num_books; i++)
  {
    l->catalog[i] = l->catalog[i + 1];
  }

  l->num_books--;

  return OK;
}
/* END [library_removeBook] */

/*------------------------------------------------------------------------*/
/* START [library_print] */
int library_print(FILE *pf, const Library *l)
{
  int i, n = 0;

  if (!pf || !l)
    return -1;

  for (i = 0; i < l->num_books; i++)
    n += book_print(pf, l->catalog[i]);

  return n;
}
/* END [library_print] */