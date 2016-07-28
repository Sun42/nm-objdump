/*
** nm.h for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:09:18 2009 christophe sundas
** Last update Sun Mar  1 22:35:55 2009 christophe sundas
*/
#ifndef __MYNM_H__

# define __MYNM_H__
#include <elf.h>
#define ERROR_FORMAT "File format not recognized"
void		mynm(int ac, char **av);
void		parse_file(char *name);
void		choose_type(void *buf, char *name, int size);
void		parse_headernm(void *buf, char *name, int size);
void		my_put_nbr_error(int numerror);
void		my_putstr_error(char *error);
char		*select_type(int elftype);
char		*select_machine(int machine_type);

/*
** header elf
*/
char		*get_os(Elf32_Ehdr *elf);
char		*get_elfclass(Elf32_Ehdr *elf);
int		check_magic_type(Elf32_Ehdr *elf);
int		check_type_elf(Elf32_Ehdr *elf, char *name);
int		check_limit_elfheader(Elf32_Ehdr *elf, char *limit);
char		*select_type(int elftype);
char		*select_machine(int machine_type);

/*
** sections
*/

void		affiche_header_section(Elf32_Shdr *section);
void		afsct(Elf32_Shdr *s, char *buf, char *startadr, Elf32_Shdr *snm);
Elf32_Shdr	*get_section(int nb, Elf32_Ehdr *elf, char *buf, char *limit);
char		*get_sect_name(Elf32_Shdr *sect, Elf32_Shdr *scnm, char *buf);
Elf32_Shdr	*get_sect_strtab(Elf32_Ehdr *elf, Elf32_Shdr *snm, char *buf, char *limit);

/*
**
*/
void		afsct(Elf32_Shdr *s, char *buf, char *startadr, Elf32_Shdr *snm);
void		affiche_header_section(Elf32_Shdr *section);
Elf32_Shdr	*get_section(int nb, Elf32_Ehdr *elf, char *buf, char *limit);
void		parse_header_armode(void *buf, char *name, int size);
int		check_ar_type(void *buf);

/*
** symbol
*/

void		print_symbol_type(int sym_type);
void		print_symbol_bind(int sym_bind);
int		is_valid_symbol_type(Elf32_Sym *sym_tab);
void		get_sym_table(Elf32_Shdr *section, Elf32_Shdr *section_name, char *buf, char *limit);
char		*get_symbol_name(char *buf, Elf32_Shdr *sect_nam, Elf32_Sym *sym_tab);
char		get_letter(Elf32_Sym *sym_tab, char *buf, char *limit);
Elf32_Shdr	*sect_from_symbol(Elf32_Sym *sym_tab, char *buf, char *limit);
int		is_valid_addr(unsigned int limit, unsigned int name_addr);
#endif
