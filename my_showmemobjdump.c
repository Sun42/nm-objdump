/*
** my_showmemobjdump.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:16:15 2009 christophe sundas
** Last update Sun Mar  1 09:18:00 2009 christophe sundas
*/
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_showmem.h"

int	my_showmem2(char *str, int size, char *start_addr)
{
  int	i;

  i = 0;
  while (i < size)
    {
      print_addr(start_addr + i);
      my_showmemobjdump(&str[i], size - i);
      i = i + 16;
    }
  return (0);
}

void    my_showmemobjdump(char *str, int size)
{
  print_hexaobjdump(str, size);
  print_ascii(str, size);
  my_putchar('\n');
}

void	print_hexaobjdump(char *str, int size)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      if ((i % 4) == 0)
        my_putchar(' ');
      if (i < size)
        my_put_nbr_base_pad(str[i], "0123456789abcdef", 2);
      else
        my_putchar(' ');
      i++;
    }
}
