/*
** symbol2.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 20:15:32 2009 christophe sundas
** Last update Sun Mar  1 22:33:14 2009 christophe sundas
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

void	print_symbol_bind(int sym_bind)
{
  if (sym_bind == 0)
    printf("STB SYMBOL local symbol \n");
  if (sym_bind == 1)
    printf("STB GLOBAL global symbol \n");
  if (sym_bind == 2)
    printf("STB WEK \n");
  if (sym_bind == 13)
    printf("STB LOPROC \n");
  if (sym_bind == 15)
    printf("STB HIPROC \n");
}

void	print_symbol_type(int sym_type)
{
  printf("sym_tab->st_info#type : \n");
  if (sym_type == 0)
    printf("STT_NOTYPE \n");
  if (sym_type == 1)
    printf("STT_OBJECT \n");
  if (sym_type == 2)
    printf("STT FUNC \n");
  if (sym_type == 3)
    printf("STT SECTION \n");
  if (sym_type == 4)
    printf("STT FILE \n");
  if (sym_type == 13)
    printf("STT_LOPROC \n");
  if (sym_type == 15)
    printf("STT_HIPROC \n");
}

int	is_valid_addr(unsigned int limit, unsigned int name_addr)
{
  if (limit > name_addr)
    return (1);
  return (0);
}
