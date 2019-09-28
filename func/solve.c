/* ********************* */
/* ***** solve_lsq ***** */
/* ********************* */

#include <stdlib.h>
#include "ft_func.h"

/* Функция init_smap предназначена для инициализации карты поиска. */
/* Т.е. заполнения ее нулями для символов "препятствий" */
/* и единицами для символов "пустоты" */
/* В качестве аргументов функции передаются: указатель на карту поиска, */
/* карта, ее размер и легенда */
void	init_smap(int ***search_map, char **map, int size[2], char leg[3])
{
  int	**s;
  int	row;
  int	col;

  s = *search_map;
  row = 0;
  while (row < size[0])
    {
      col = 0;
      while (col < size[1])
	{
	  if (map[row][col] == leg[0])
	    s[row][col] = 1; /* символ "пустоты" заменяется на 1 */
	  if (map[row][col] == leg[1])
	    s[row][col] = 0; /* символ "препятствие" заменяется на 0 */
	  col++;
	}
      row++;
    }
}

/* Функция min предназначена для поиска минимального из трех чисел */
int	min(int a, int b, int c)
{
  int	res;
  
  res = a;
  if (res > b)
    res = b;
  if (res > c)
    res = c;
  return (res);
}

/* Функция searhc_lsq_cell предназначена для рассчета ячеек, */
/* из которых возможно построение наибольшего квадрата. */
/* В качестве аргументов функции передаются: указатель на */
/* карту поиска, размер карты */
void	search_lsq(int ***search_map, int size[2])
{
  int	**s;
  int	row;
  int	col;

  s = *search_map;
  row = 1; /* первую строку и столбец рассчитывать не нужно */
  while (row < size[0])
    {
      col = 1;
      while (col < size[1])
	{
	  if (s[row][col] == 1)
	    s[row][col] += min(s[row][col - 1], s[row - 1][col], s[row - 1][col - 1]);
	  col++;
	}
      row++;
    }
}

/* Функция find_cell нужна для поиска значения и положения ячейки, */
/* которая будет являться правым нижним углом искомого квадрата. */
/* В качестве аргумента функция принимает карту поиска, размер карты и */
/* пустой массив для записи в него 3-х чисел: */
/*номер строки и колонки ячейки, значение ячейки */
void	find_cell(int **s, int size[2], int max_data[3])
{
  int	row;
  int	col;

  row = 0;
  while (row < size[0])
    {
      col = 0;
      while (col < size[1])
	{
	  /* если будет несколько равных ячеек, данные сохранятся для первой встреченной */
	  if (max_data[2] < s[row][col])
	    {
	      max_data[2] = s[row][col];
	      max_data[1] = col;
	      max_data[0] = row;
	    }
	  col++;
	}
      row++;
    }
}

/* Функция print_lsq предназначена для воспроизводства */
/* наибольшего квадрата на карте */
/* В качестве аргументов функции передаются: указатель на карту поиска, */
/* карта, ее размер и легенда */
void	print_lsq(int **sm, char **map, int size[2], char leg[3])
{
  int	mdata[3] = {0};
  int	row;
  int	col;
  int	lrow;
  int	lcol;

  find_cell(sm, size, mdata);
  /* номер строки левой верхней ячейки искомого квадрата */ 
  lrow = mdata[0] - mdata[2];
  row = 0;
  while (row < size[0])
    {
      col = 0;
      /* номер колонки левой верхней ячейки искомого квадрата */
      lcol = mdata[1] - mdata[2];
      while (col < size[1])
	{
	  if ((row > lrow && row < mdata[0] + 1) &&
	      (col > lcol && col < mdata[1] + 1))
	      ft_putchar(leg[2]);
	  else
	    ft_putchar(map[row][col]);
	  col++;
	}
      ft_putchar('\n');
      row++;
    }
}

/* Функция solve_lsq предназначена для расчета и */
/* построения наибольшего квадрата для заданной карты */
/* В качестве аргументов передаются: указатель на карту, */
/* размеры карты, легенда карты. */
void	solve_lsq(char **map, int size[2], char leg[3])
{
  int	**search_map;
  int	i;

  i = 0;
  search_map = (int **)malloc(size[0] * sizeof(int *));
  while (i < size[0])
    {
      search_map[i] = (int *)malloc(size[1] * sizeof(int));
      i++;
    }
  init_smap(&search_map, map, size, leg);
  search_lsq(&search_map, size);
  print_lsq(search_map, map, size, leg);

  /* освобождение памяти под карту поиска */
  i = 0;
  while (i < size[0])
    {
      free(search_map[i]);
      i++;
    }
  free(search_map);
}
