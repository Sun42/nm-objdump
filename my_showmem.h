/*
** my_showmem.h for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:08:55 2009 christophe sundas
** Last update Sun Mar  1 09:08:56 2009 christophe sundas
*/
#ifndef __SHOW_ALLOCMEM_H__
# define __SHOW_ALLOCMEM_H__

int	my_showmem(char *str, int size);
void	my_put_nbr_base_pad(unsigned int nbr, char *base, int pad);
void	print_addr(char *str);
void	print_hexa(char *str, int size);
void	print_ascii(char *str, int size);
void	my_showmem16(char *str, int size);
void	my_putchar(char c);
int	my_strlen(char *str);
void	my_putstr(char *str);

/*
** nm objdump
*/
int	my_showmem2(char *str, int size, char *start_addr);
void	print_hexaobjdump(char *str, int size);
void	my_showmemobjdump(char *str, int size);
#endif
