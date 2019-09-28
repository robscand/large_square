/* ***************************** */
/* ***** ft_list_push_back ***** */
/* ***************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, char *data)
{
  /* сначала осуществляется `->`, затем `*` - нужно изменить приоритет */
  /* без указателя было бы так: (*begin_list)->next */
  /* также нужно сохранить указатель на первый элемент в списке */
  /* для этого вводим новый указатель */
  t_list *list;

  list = *begin_list;
  if (list)
    {
      while (list->next) 
	list = list->next;
      list->next = ft_create_elem(data);
    }
  else
    *begin_list = ft_create_elem(data);
}
