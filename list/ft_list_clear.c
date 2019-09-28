/* ************************* */
/* ***** ft_list_clear ***** */
/* ************************* */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
  t_list *next;

  while (*begin_list)
    {
      next = (*begin_list)->next;
      free(*begin_list);
      *begin_list = next;
    }
  begin_list = NULL;
}
