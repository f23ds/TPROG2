#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "types.h"

/* Include here any other headers you need */
#define MAX_QUEUE 23

struct _Queue
{
  void *data[MAX_QUEUE];
  int front;
  int rear;
};

/**
 * @brief Returns a new queue that interleaves the elements in the first and
 * second halves of a queue.
 *
 * Examples:
 *
 * Input:  [1, 2, 3, 4, 5, 6]
 * Output: [1, 4, 2, 5, 3, 6]
 *
 * Input:  [1, 2, 3, 4, 5]
 * Output: [1, 4, 2, 5, 3]
 *
 * @see https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
 *
 * @param q, pointer to the queue.
 *
 * @return A new queue with the elements in the first and second halves of q
 * interleaved. See example above.
 **/
Queue *interleave(Queue *q)
{
  Queue *qinter = NULL;
  size_t size;
  void *last_ele = NULL;
  int i;

  qinter = queue_new();
  if (!qinter)
    return NULL;

  size = queue_size(q);

  if (size % 2 == 0)
  {
    /* Almacenamos la primera mitad de q en qinter */
    for (i = 0; i < size / 2; i++)
    {
      queue_push(qinter, queue_getFront(q));
      queue_pop(q);
    }

    /* Intercalamos los elementos de qinter y lo restante de q */
    for (i = 0; i < size / 2; i++)
    {
      queue_push(qinter, queue_getFront(qinter));
      queue_pop(qinter);
      queue_push(qinter, queue_getFront(q));
      queue_pop(q);
    }
  }
  else
  {
    /* Almacenamos la primera mitad de q en qinter */
    for (i = 0; i < (size + 1) / 2; i++)
    {
      queue_push(qinter, queue_getFront(q));
      queue_pop(q);
    }

    /* Añadimos la segunda mitad intercalando */
    for (i = 0; i < (size - 1) / 2; i++)
    {
      queue_push(qinter, queue_getFront(qinter));
      queue_pop(qinter);
      queue_push(qinter, queue_getFront(q));
      queue_pop(q);
    }

    last_ele = queue_pop(qinter);
    queue_push(qinter, last_ele);
  }

  return qinter;
}

/**
 * @brief Concatenates two queues by adding all the elements in the second queue
 * to the first one. Upon successful exit the first queue will contain the
 * elements from both queues and the second queue will be empty. In case of
 * error the two queues will be unchanged.
 *
 * Example:
 *
 * Before concatenation: qa = [1, 2, 3, 4, 5, 6]
 *                       qb = [1, 2, 3, 4]
 *
 * After concatenation:  qa = [1, 2, 3, 4, 5, 6, 1, 2, 3, 4]
 *                       qb = []
 *
 * @param qa, pointer to the first queue.
 * @param qb, pointer to the second queue.
 *
 * @return OK on success, ERROR if there is any error. In case of error the
 * contents of both queues must remain unchanged.
 **/
Status concatenate(Queue *qa, Queue *qb)
{
  size_t size1, size2;
  int i, j;

  if (!qa || !qb)
    return ERROR;

  size1 = queue_size(qa);
  size2 = queue_size(qb);

  for (i = size1; i < size1 + size2; i++)
  {
    if (queue_push(qa, queue_getFront(qb)) == ERROR)
    {
      /* Si falla debemos returnear las colas a sus valores por defecto */
      queue_push(qb, queue_getBack(qa));
      queue_pop(qa);
    }
    else
    {
      queue_pop(qb);
    }
  }

  return OK;
}
