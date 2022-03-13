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

int *_space_pos(char *strin, int num_spaces)
{
  int i, j, len, *space_pos = NULL;

  /* Comprobamos strin */
  if (!strin)
    return NULL;

  len = strlen(strin);

  /* Guardamos memoria para las posiciones de los espacios dentro de la cadena */
  space_pos = (int *)malloc((num_spaces + 1) * sizeof(int));

  /* Comprobamos la reserva de memoria */
  if (!space_pos)
    return NULL;

  /* Iteramos sobre la cadena para saber la posición de los espacios y almacenarlas en el array */
  for (i = 0, j = 0; i < len; i++)
  {
    if (strin[i] == ' ')
    {
      space_pos[j] = i;
      j++;
    }
  }

  space_pos[j] = i;

  return space_pos;
}

int _num_spaces(const char *strin)
{
  int i, len, num_spaces = 0;

  if (!strin)
    return -1;

  len = strlen(strin);

  /* Iteramos sobre la cadena para saber el número de espacios de la cadena */
  for (i = 0; i < len; i++)
  {
    if (strin[i] == ' ')
    {
      num_spaces++;
    }
  }

  return num_spaces;
}

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
  int len, i;
  char *strout = NULL;

  /* Comprobamos el puntero str */
  if (!str)
    return NULL;

  len = strlen(str);

  /* Reservamos memoria para la cadena de salida */
  strout = (char *)malloc((len + 1) * sizeof(char));

  /* Comprobamos la reserva de memoria */
  if (!strout)
    return NULL;

  /* Inicializamos una pila para guardar los caracteres de la cadena de entrada */
  s = stack_init();

  /* Comprobamos la pila */
  if (!s)
  {
    free(strout);
    return NULL;
  }

  /* Guardamos los caracteres de la cadena de entrada en la pila uno por uno */
  for (i = 0; i < len; i++)
  {
    stack_push(s, &str[i]);
  }

  /* Ahora hacemos pop en la pila iterativamente hasta llenar la cadena de salida */
  for (i = 0; i < len; i++)
  {
    if (!stack_isEmpty(s))
    {
      strout[i] = (*(char *)stack_pop(s));
    }
  }

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
  Stack *s;
  int i, j, flag = 0, len, *space_pos = NULL, num_spaces;

  /* Comprobamos los punteros */
  if (strin == NULL || strout == NULL)
    return ERROR;

  len = strlen(strin);

  s = stack_init();

  if (!s)
    return ERROR;

  /* Extraemos el número de espacios de la cadena */
  num_spaces = _num_spaces(strin);

  /* Extraemos el array con las posiciones de los espacios */
  space_pos = _space_pos(strin, num_spaces);

  if (num_spaces == 0)
  {
    /* Guardamos los caracteres de la cadena de entrada en la pila uno por uno */
    for (i = 0; i < len; i++)
    {
      stack_push(s, &strin[i]);
    }

    /* Ahora hacemos pop en la pila iterativamente hasta llenar la cadena de salida */
    for (i = 0; i < len; i++)
    {
      if (!stack_isEmpty(s))
      {
        strout[i] = (*(char *)stack_pop(s));
      }
    }
  }
  else if (num_spaces != -1)
  {
    flag = 0;
    /* Ahora introducimos cada palabra en la pila e invertimos */
    for (i = 0; i < num_spaces + 1; i++)
    {
      /* Introducimmos palabra */
      for (j = flag; j < space_pos[i]; j++)
      {
        stack_push(s, &strin[j]);
      }

      /* Invertimos */
      for (j = flag; j < space_pos[i]; j++)
      {
        if (!stack_isEmpty(s))
        {
          strout[j] = *(char *)stack_pop(s);
        }
      }

      flag = space_pos[i] + 1;

      /* Añadimos el espacio a la cadena */
      stack_push(s, &strin[space_pos[i]]);
      strout[j] = *(char *)stack_pop(s);
    }
  } else {
    return ERROR;
  }

  /* Frees */
  stack_free(s);
  free(space_pos);

  return OK;
}
