/* ******************* */
/* ***** ft_list ***** */
/* ******************* */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
  struct s_list	*next;
  char		data[1]; /* элемент карты состоит из 1 символа */
}		t_list;

t_list		*ft_create_elem(char *data);
void		ft_list_push_back(t_list **begin_list, char *data);
int		ft_list_size(t_list *begin_list);
void		ft_list_clear(t_list **begin_list);
void		ft_print_list(t_list *begin_list);

#endif
