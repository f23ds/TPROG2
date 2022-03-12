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
  int len = strlen(str), i;
  char *strout;

  /* Comprobamos el puntero str */
  if (!str)
    return NULL;


  /* Reservamos memoria para la cadena de salida */
  strout = (char *)malloc((len + 1) * sizeof(char));

  /* Comprobamos la reserva de memoria */
  if (!strout)
    return NULL;

  /* Inicializamos una pila para guardar los caracteres de la cadena de entrada */
  s = stack_init();

  /* Comprobamos la pila */
  if (!s)
    return NULL;

  /* Guardamos los caracteres de la cadena de entrada en la pila uno por uno */
  for (i = 0; i < len + 1; i++)
  {
    if (str[i] != '\0')
    {
      stack_push(s, &str[i]);
    }
  }

  /* Ahora hacemos pop en la pila iterativamente hasta llenar la cadena de salida 
  for (i = 0; i < len + 1; i++)
  {
    if (!stack_isEmpty(s))
    {
      strcpy(&strout[i], (char *)stack_pop(s));
    }
  } */

  stack_free(s);
  return str;
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