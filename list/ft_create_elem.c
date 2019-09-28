/* ************************** */
/* ***** ft_create_elem ***** */
/* ************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(char *data)
{
  t_list *elem;

  elem = malloc(sizeof(t_list) + 1);
  if (elem)
    {
      /* Используестя копирование по значению строк, потому что через "=" копируется не значение строки,
       * а ее адрес в памяти. Который освобождается после выхода из области видимости. */
      *(elem->data) = *data;
      elem->next = NULL;
    }
  return (elem);
}
