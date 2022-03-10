#include "stack_fDoble.h"
#include "file_utils.h"
/* Include here any other headers you need */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 100

struct _Stack
{
  void *data[MAX_STACK];
  int top;
};

/**
 * @brief: Reverses a string
 * @param str, String to reverse
 * @return A newly allocated string with the reversed string
 **/

char *string_invert(char *str)
{
  /* Es OBLIGATORIO usar una pila para implementar esta función */
  /* No hacerlo implica un NO APTO */
  Stack *s;
  int len, i = 0;
  char *strout = NULL, *tmp = NULL;

  /* Comprobamos que el puntero str no es NULL */
  if (str == NULL)
    return NULL;

  /* La cadena de entrada y de salida deben tener la misma longitud, así que reservamos memoria para esta */
  len = strlen(str);

  strout = (char *)malloc(len * sizeof(char));

  /* Introducimos los caracteres en la pila */
  s = stack_init();

  if (s == NULL)
    return NULL;

  for (i = len+1; i >= 0; i--)
  {
    stack_push(s, &str[i]);
  }

  /* Ahora queremos introducir los caracteres que hemos almacenado en la pila en strout */
  i = 0;
  while (!stack_isEmpty(s)) {
    tmp = (char *) stack_pop(s);
    strcpy(&strout[i], tmp);
  }

  stack_free(s);

  return strout; // remove this line once you add your code
}

/**
 * @brief: Reverse the words of an input string to an output string.
 *
 * @example: "Hello World" => "olleH dlroW"
 * The words in the input string are separated by a space character.
 * The strings may not overlap, and the destination string strout
 * must be large enough to receive the inverted expression.
 *
 * @param strout, Pointer to the output buffer
 * @param strin, Pointer to the input expression
 * @return The function returns OK or ERROR
 **/

Status reverseWords(char *strout, char *strin)
{
  /* It is MANDATORY that you use a stack to implement this function */
  /* Failure to do so will result in a FAIL grade */

  /* Es OBLIGATORIO usar una pila para implementar esta función */
  /* No hacerlo implica un NO APTO */

  /* YOUR CODE HERE - TU CÓDIGO AQUÍ */

  return ERROR; // remove this line once you add your code
};