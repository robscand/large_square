/* ******************* */
/* ***** ft_func ***** */
/* ******************* */

#ifndef FT_FUNC_H
# define FT_FUNC_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int	ft_atoi(char *str);
int	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	solve_lsq(char **map, int size[2], char leg[3]);

#endif
