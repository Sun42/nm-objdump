/*
** ar_mode.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:11:31 2009 christophe sundas
** Last update Sun Mar  1 09:11:32 2009 christophe sundas
*/
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <ar.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "objdump.h"
#include "my_showmem.h"

void	parse_header_armode(void *buf, char *name, int size)
{
  name = name;
  my_showmem((char *)buf, size);
}

int	check_ar_type(void *buf)
{
  char	*name;

  name = (char *) buf;
  if (strncmp(name, ARMAG, SARMAG) == 0)
    return (1);
  return (0);
}
