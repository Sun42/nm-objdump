/*
** header_elf.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:31:54 2009 christophe sundas
** Last update Sun Mar  1 21:28:51 2009 christophe sundas
*/
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ar.h>
#include "nm.h"
#include "my_showmem.h"

char	*get_os(Elf32_Ehdr *elf)
{
  if (elf->e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
    return ("FreeBSD");
  if (elf->e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
    return ("Solaris");
  if (elf->e_ident[EI_OSABI] == ELFOSABI_LINUX)
    return ("Linux");
  if (elf->e_ident[EI_OSABI] == ELFOSABI_NETBSD)
    return ("NetBSD");
  return (NULL);
}

char	*get_elfclass(Elf32_Ehdr *elf)
{
  if (elf->e_ident[EI_CLASS] == ELFCLASS32)
    return ("elf32");
  if (elf->e_ident[EI_CLASS] == ELFCLASS64)
    return ("elf64");
  if (elf->e_ident[EI_CLASS] == ELFCLASSNONE)
    return ("unknown elf class \n");
  return ("unknown elf class \n");
}

int	check_magic_type(Elf32_Ehdr *elf)
{
  if (elf->e_ident[EI_MAG0] != ELFMAG0)
    return (-1);
  if (elf->e_ident[EI_MAG1] != ELFMAG1)
    return (-1);
  if (elf->e_ident[EI_MAG2] != ELFMAG2)
    return (-1);
  if (elf->e_ident[EI_MAG3] != ELFMAG3)
    return (-1);
  return (0);
}

int	check_type_elf(Elf32_Ehdr *elf, char *name)
{
  if (elf->e_type == ET_NONE || elf->e_type > 4)
    {
      if (printf("nm: %s: %s \n", name, ERROR_FORMAT) == -1)
        my_putstr_error("printf error \n");
      return (-1);
    }
  if (strcmp(get_elfclass(elf), "elf32") != 0)
    {
      my_putstr_error("not elf32 elf class \n");
      return (-1);
    }
  return (0);
}

int	check_limit_elfheader(Elf32_Ehdr *elf, char *limit)
{
  if (((char *)elf->e_shoff > limit) || ((char *)elf->e_phoff > limit))
    {
      my_putstr_error("File corrupted \n");
      return (-1);
    }
  return (0);
}
