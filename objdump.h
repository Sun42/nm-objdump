/*
** objdump.h for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:09:38 2009 christophe sundas
** Last update Sun Mar  1 11:40:50 2009 christophe sundas
*/
#ifndef __MYOBJDUMP_H__

# define __MYOBJDUMP_H__
#include <elf.h>
#define ERROR_FORMAT "File format not recognized"

/*
** my_objdump.c
*/
void		myobjdump(int ac, char **av);
void		parse_file(char *name);
void		parse_header(void *buf, char *name, int size);
void		choose_type(void *buf, char *name, int size);

/*
** ar mode
*/
int		check_ar_type(void *buf);
void		parse_header_armode(void *buf, char *name, int size);

/*
** my_put_error.c
*/
void		my_put_nbr_error(int numerror);
void		my_putstr_error(char *error);

/*
** sections.c
*/
void		affiche_header_section(Elf32_Shdr *section);
void		afsct(Elf32_Shdr *s, char *buf, char *startadr, Elf32_Shdr *snm);
Elf32_Shdr	*get_section(int nb, Elf32_Ehdr *elf, char *buf, char *limit);
char		*get_sect_name(Elf32_Shdr *sect, Elf32_Shdr *sect_name, char *buf);
Elf32_Shdr	*get_sect_strtab(Elf32_Ehdr *elf, Elf32_Shdr *snm, char *buf);

/*
**header_elf.c
*/
char		*select_machine(int machine_type);
char		*select_type(int elftype);
int		check_type_elf(Elf32_Ehdr *elf, char *name);
int		check_magic_type(Elf32_Ehdr *elf);
char		*get_elfclass(Elf32_Ehdr *elf);
char		*get_os(Elf32_Ehdr *elf);
int		check_limit_elfheader(Elf32_Ehdr *elf, char *limit);


#endif
