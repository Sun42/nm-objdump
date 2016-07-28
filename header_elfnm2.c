/*
** header_elf2.c for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar  1 09:40:36 2009 christophe sundas
** Last update Sun Mar  1 21:29:22 2009 christophe sundas
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

char	*select_machine(int machine_type)
{
  if (machine_type == EM_NONE)
    return ("Unknown machine.");
  if (machine_type == EM_M32)
    return ("AT&T WE 32100.");
  if (machine_type == EM_SPARC)
    return ("Sun Microsystems SPARC.");
  if (machine_type == EM_386)
    return ("i386.");
  if (machine_type == EM_68K)
    return ("Motorola 68000.");
  if (machine_type == EM_88K)
    return ("Motorola 88000.");
  if (machine_type == EM_486)
    return ("i486");
  if (machine_type == EM_860)
    return ("Intel 80860.");
  if (machine_type == EM_MIPS)
    return ("HPPA.");
  if (machine_type == EM_ALPHA)
    return ("Compaq [DEC] Alpha.");
  return (NULL);
}

char	*select_type(int elftype)
{
  if (elftype == ET_NONE)
    return ("An unknown type");
  if (elftype == ET_REL)
    return ("A relocatable file");
  if (elftype == ET_EXEC)
    return ("An executable file.");
  if (elftype == ET_DYN)
    return ("A shared object.");
  if (elftype == ET_CORE)
    return ("A core file.");
  return (NULL);
}
