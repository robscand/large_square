/* ********************* */
/* ***** ft_putstr ***** */
/* ********************* */

#include "ft_func.h"

void	ft_putstr(char *str)
{
  while (*str)
    {
      ft_putchar(*str);
      str++;
    }
}
