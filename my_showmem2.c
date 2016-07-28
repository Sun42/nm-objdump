/*
** my_showmem2.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:08:39 2009 christophe sundas
** Last update Sun Mar  1 09:20:04 2009 christophe sundas
*/
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_showmem.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_put_nbr_base_pad(unsigned int nbr, char *base, int pad)
{
  int	base_len;

  base_len = my_strlen(base);
  if (pad > 0)
    {
      my_put_nbr_base_pad(nbr / base_len, base, pad - 1);
      my_putchar(base[nbr % base_len]);
    }
}
