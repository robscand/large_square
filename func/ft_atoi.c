/* ******************* */
/* ***** ft_atoi ***** */
/* ******************* */

int	ft_atoi(char *str)
{
  int res;
  int neg;

  neg = 1;
  res = 0;
  while (*str == 32 || (*str >= 9 && *str <= 13))
      str++;
  if (*str == '+' || *str == '-')
    {
      if (*str == '-')
	neg = -1;
      str++;
    }
  while (*str >= 48 && *str <= 57)
    {
      res = res * 10 + (*str - '0');
      str++;
    }
  return (res * neg);
}
