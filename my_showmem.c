/*
** my_showmem.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:13:32 2009 christophe sundas
** Last update Sun Mar  1 09:18:08 2009 christophe sundas
*/
#include "my_showmem.h"

void	print_addr(char *str)
{
  my_put_nbr_base_pad((unsigned int)str, "0123456789abcdef", 8);
  my_putchar(':');
}

void	print_hexa(char *str, int size)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      if ((i % 2) == 0)
	my_putchar(' ');
      if (i < size)
	my_put_nbr_base_pad(str[i], "0123456789abcdef", 2);
      else
	my_putstr( " ");
      i++;
    }
}

void	print_ascii(char *str, int size)
{
  int	i;

  my_putstr(" ");
  i = 0;
  while ((i < 16) && (i < size))
    {
      if ((str[i] >= 32) && (str[i] < 127))
	my_putchar(str[i]);
      else
	my_putchar('.');
      i++;
    }
}

void	my_showmem16(char *str, int size)
{
  print_addr(str);
  print_hexa(str, size);
  print_ascii(str, size);
  my_putchar('\n');
}

int	my_showmem(char *str, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      my_showmem16(&str[i], size -  i);
      i = i + 16;
    }
  return (0);
}
