/*
** symbol.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 20:15:17 2009 christophe sundas
** Last update Sun Mar  1 22:50:31 2009 christophe sundas
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

void		get_sym_table(Elf32_Shdr *sec, Elf32_Shdr *secnm, char *buf, char *lim)
{
  Elf32_Sym	*sym_tab;
  int		nbsection;
  int		i;
  
  i = 0;
  if ((secnm == NULL) || (sec == NULL))
    return ;
  nbsection = sec->sh_size / sec->sh_entsize;
  while (i < nbsection)
    {
      sym_tab = (Elf32_Sym *)((unsigned int) buf + sec->sh_offset + (i * sec->sh_entsize));
      if (is_valid_symbol_type(sym_tab) && sym_tab->st_name > 0)
       {
	 if (sym_tab->st_value > 0)
	   printf("%.08x ", (unsigned)sym_tab->st_value);
	 else
	   printf("         ");
	 printf("%c ", get_letter(sym_tab, buf, lim));
	 if (is_valid_addr((unsigned int)lim, ((unsigned int)(buf + sym_tab->st_name + secnm->sh_offset))))
	   printf("%s \n", (char *)((unsigned int) (buf + secnm->sh_offset + sym_tab->st_name)));
       }
      i++;
   }
}

Elf32_Shdr	*sect_from_symbol(Elf32_Sym *sym_tab, char *buf, char *limit)
{
  Elf32_Shdr	*section;
  Elf32_Ehdr	*elf;

  elf = (void *)buf;
  section = get_section(sym_tab->st_shndx, elf, (void *)buf, limit);
  return (section);
}

char		get_letter(Elf32_Sym *sym_tab, char *buf, char *limit)
{
  int		type;
  Elf32_Shdr	*section;
  Elf32_Ehdr	*elf;

  elf = (void *)buf;
  type = ELF32_ST_TYPE(sym_tab->st_info);
  if (type == STT_NOTYPE)
    return ('U');
  if (sym_tab->st_shndx == SHN_UNDEF)
    return ('U');
  if (sym_tab->st_shndx == SHN_ABS)
    return ('A');
  if (sym_tab->st_shndx == SHN_COMMON)
    return ('C');
  if (sym_tab->st_shndx < SHN_LORESERVE)
    {
      section = sect_from_symbol(sym_tab, (void *)buf, limit);
      if (section->sh_type == SHT_PROGBITS)
	return ('T');
      if ((section->sh_flags & SHF_WRITE) == 0)
	return ('R');
    }
  return ('?');
}

char	*get_symbol_name(char *buf, Elf32_Shdr *sect_nam, Elf32_Sym *sym_tab)
{
  char	*s;

  s = (char *)((unsigned int) (buf + sect_nam->sh_offset + sym_tab->st_name));
  return (s);
}

int	is_valid_symbol_type(Elf32_Sym *sym_tab)
{
  int	type;

  type = ELF32_ST_TYPE(sym_tab->st_info);
  if ((type == 1) || (type == 2) || (type == 3))
    return (1);
  if ((type == 0) || (type == 13) || (type == 15))
    return (1);
  return (0);
}
