/*
** sections.c for obj in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:07:36 2009 christophe sundas
** Last update Sun Mar  1 21:25:31 2009 christophe sundas
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

void	affiche_header_section(Elf32_Shdr *section)
{
  printf("section->sh_size : %i \n", (unsigned)section->sh_size);
  printf("section->sh_name : %i \n", (unsigned)section->sh_name);
  printf("section->sh_type : %i \n", (unsigned)section->sh_type);
  printf("section->sh_flags : %i \n", (unsigned)section->sh_flags);
  printf("section->sh_addr : %i \n", (unsigned)section->sh_addr);
  printf("section->sh_offset : %i \n", (unsigned)section->sh_offset);
  printf("section->sh_info : %i \n", (unsigned)section->sh_info);
  printf("section->sh_entsize : %i \n", (unsigned)section->sh_entsize);
}

void	afsct(Elf32_Shdr *s, char *buf, char *adr, Elf32_Shdr *snm)
{
  if (printf("Contents of section .%s  \n" , get_sect_name(s, snm, buf)) == -1)
    my_putstr_error("printf error \n");
  my_showmem2((char *)((unsigned int) buf + s->sh_offset), s->sh_size, adr);
  my_putchar('\n');
}

Elf32_Shdr	*get_section(int nb, Elf32_Ehdr *elf, char *buf, char *limit)
{

  Elf32_Shdr	*section;
  int		section_offset;

  section_offset = elf->e_shoff + (nb * elf->e_shentsize);
  if (((char *) ((unsigned int) (buf) + section_offset)) > limit)
    {
      my_putstr_error("File corrupted \n");
      return NULL;
    }
  section = (void *) ((unsigned int) (buf) + section_offset);
  return (section);
}

/*
** retourne la string table
*/
char	*get_sect_name(Elf32_Shdr *sect, Elf32_Shdr *snm, char *buf)
{
  char	*name;

  name = (char *)((unsigned int)buf + snm->sh_offset + 1 + sect->sh_name);
  return (name);
}

Elf32_Shdr	*get_sect_strtab(Elf32_Ehdr *e, Elf32_Shdr *sn, char *bf, char *li)
{
  Elf32_Shdr	*section;
  int		i;

  i = 0;
  while (i < e->e_shnum)
    {
      if ((section = get_section(i, e, bf, li)) == NULL)
        break ;
      if (strcmp(get_sect_name(section, sn, bf), "strtab") == 0)
	return (section);
      i++;
    }
  return (NULL);
}
