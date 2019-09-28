/* ********************* */
/* ***** ft_putnbr ***** */
/* ********************* */

#include "ft_func.h"
#define MIN_INT -2147483648

void	nbr(int num)
{
  if (num)
    {
      nbr(num/10);
      ft_putchar(num % 10 + '0');
    }
}

void	ft_putnbr(int nb)
{
  if (nb == 0)
    ft_putchar('0');
  if (nb < 0)
    {
      ft_putchar('-');
      if (nb == MIN_INT)
	{
	  nbr(nb/-10);
	  ft_putchar((nb % 10) * -1 + '0');
	}
      else
	nbr(-1 * nb);
    }
  else
    nbr(nb);
}
