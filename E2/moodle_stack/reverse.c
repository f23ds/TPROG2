#include "stack_fDoble.h"
#include "file_utils.h"
#include "types.h"
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
  Stack *s = NULL;
  int len, i = 0;
  char *strout = NULL;
  Status status = OK;

  /* Comprobamos el puntero str */
  if (!str)
    return ERROR;

  len = strlen(str);

  /* Reservamos memoria para la cadena de salida */
  strout = (char *)calloc((len + 1), sizeof(char));

  /* Comprobamos la reserva de memoria */
  if (!strout)
    return ERROR;

  /* Inicializamos una pila para guardar los caracteres de la cadena de entrada */
  s = stack_init();

  /* Comprobamos la pila */
  if (!s)
  {
    free(strout);
    return ERROR;
  }

  /* Guardamos los caracteres de la cadena de entrada en la pila uno por uno */
  while ((str[i] != '\0') && status == OK)
  {
    status = stack_push(s, &str[i]);
    i++;
  }

  /* Evaluamos status al final del bucle while */
  if (status == ERROR)
  {
    char_free(strout);
    stack_free(s);
    return ERROR;
  }

  i = 0;
  /* Ahora hacemos pop en la pila iterativamente hasta llenar la cadena de salida */
  while (!stack_isEmpty(s))
  {
    strout[i] = (*(char *)stack_pop(s));
    i++;
  }

  /* El último caracter siempre tiene que ser el \0 */
  strout[len] = '\0';
  stack_free(s);
  return strout;
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
  Stack *s = NULL;
  int i = 0, j = 0;
  Status status = OK;

  /* Comprobamos los punteros */
  if (strin == NULL || strout == NULL)
    return ERROR;

  s = stack_init();

  if (!s)
    return ERROR;

  while (status == OK && strin[i] != '\0')
  {
    /* Si el caracter no es un espacio lo introducimos en la pila */
    if (strin[i] != ' ') {
      status = stack_push(s, &strin[i]);
      i++;
    } else { /* al haber encontrado un espacio debemos reversear la palabra */
      while (stack_isEmpty(s) == FALSE) {
        strout[j] = (*(char *) stack_pop(s));
        j++;
      }
      /* Añadimos el espacio en la última posición */
      strout[j] = ' ';
      i++;
      j++;
    }
  }

  /* Realizamos el control de errores */
  if (status == ERROR) {
    stack_free(s);
    return ERROR;
  }

  /* Vacíamos la pila con la última palabra */
  while (stack_isEmpty(s) == FALSE) {
    strout[j] = (*(char *) stack_pop(s));
    j++;
  }

  /* El último caracter debe ser \0 */
  strout[j] = '\0';
  stack_free(s);

  return OK;
}
