/*
** nm.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:09:09 2009 christophe sundas
** Last update Sun Mar  1 21:07:34 2009 christophe sundas
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
#include "nm.h"
#include "my_showmem.h"

#define ERROR_FORMAT "File format not recognized"

int	main(int ac, char **av)
{
  if (ac > 0)
    mynm(ac, av);
  return (0);
}

void	mynm(int ac, char **av)
{
  int	i;

  i = 1;
  if (ac == 1)
    parse_file("a.out");
  if (ac > 1)
    {
      while (i < ac)
        {
          parse_file(av[i]);
          i++;
        }
    }
}

void	parse_file(char *name)
{
  int		fd;
  void		*buf;
  struct stat	s;

  if ((fd = open(name, O_RDONLY)) == -1)
    {
      my_putstr_error("Error open \n");
      return ;
    }
  if (fstat(fd, &s) == -1)
    {
      my_putstr_error("Error fstats \n");
      return ;
    }
  if ((buf = mmap(NULL, s.st_size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
    {
      my_putstr_error("Error mmap \n");
      return ;
    }
  choose_type(buf, name, s.st_size);
  if (munmap(buf, s.st_size) == -1)
    my_putstr_error("Error munmap \n");
  if (close(fd) == -1)
    my_putstr_error("Error close \n");
}

void	choose_type(void *buf, char *name, int size)
{
  Elf32_Ehdr	*elf;

  elf = buf;
  if (size < 8)
    return ;
  if (check_magic_type(elf) == 0)
    parse_headernm(buf, name, size);
  if (check_ar_type(buf) == 1)
    parse_header_armode(buf, name, size);
}

void		parse_headernm(void *buf, char *name, int size)
{
  int		i;
  char		*limit;
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*section;
  Elf32_Shdr	*section_name;
  Elf32_Shdr	*section_strtab;

  elf = buf;
  if (check_type_elf(elf, name) == -1)
    return ;
  limit = (char *) ((unsigned int) buf + size);
  if (check_limit_elfheader(elf, limit) == -1)
    return ;
  i = 0;
  if ((section_name = get_section(elf->e_shstrndx, elf, buf, limit)) == NULL)
    return ;
  section_strtab = get_sect_strtab(elf, section_name, buf, limit);
  while (i < elf->e_shnum)
    {
      section = get_section(i, elf, buf, limit);
      if ((section->sh_type == SHT_SYMTAB) || (section->sh_type == SHT_DYNSYM))
	get_sym_table(section, section_strtab, buf, limit);
      i++;
    }
}
