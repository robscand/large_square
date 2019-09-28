/* ************************* */
/* ***** ft_print_list ***** */
/* ************************* */

#include "ft_func.h"
#include "ft_list.h"

void	ft_print_list(t_list *begin_list)
{
  while(begin_list)
    {
      ft_putstr(begin_list->data);
      begin_list = begin_list->next;
    }
}
