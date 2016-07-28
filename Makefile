##
## Makefile for  in /u/all/sundas_c/cu/rendu/unix/projet/my_nm/nm-objdump
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Sun Mar  1 09:08:07 2009 christophe sundas
## Last update Sun Mar  1 21:39:37 2009 christophe sundas
##
CC_FreeBSD      =       gcc
CC_solaris      =       /usr/sfw/bin/gcc
CC              =       $(CC_${OSTYPE})

CFLAGS += -W -Wall -ansi -pedantic
NAME_NM = my_nm
SRC_NM = nm.c \
	my_showmem.c \
	my_showmem2.c \
	my_showmemobjdump.c \
	my_put_errornm.c \
	sectionsnm.c \
	header_elfnm.c \
	header_elfnm2.c \
	ar_modenm.c \
	symbol.c \
	symbol2.c
OBJ_NM = $(SRC_NM:.c=.o)

NAME_OBJDUMP = my_objdump
SRC_OBJDUMP = objdump.c \
	my_showmem.c \
	my_showmem2.c \
	my_showmemobjdump.c \
	my_put_error.c \
	sections.c \
	header_elf.c \
	header_elf2.c \
	ar_mode.c
OBJ_OBJDUMP = $(SRC_OBJDUMP:.c=.o)
RM = rm -f

#NM
$(NAME_NM) : $(OBJ_NM)
	$(CC) -o $(NAME_NM) $(OBJ_NM)

clean_my_nm : 
	$(RM) $(OBJ_NM)

fclean_my_nm : clean_my_nm 
	$(RM) $(NAME_NM)

re_my_nm : fclean_my_nm $(NAME_NM)

#OBJDUMP
$(NAME_OBJDUMP) : $(OBJ_OBJDUMP)
		$(CC) -o $(NAME_OBJDUMP) $(OBJ_OBJDUMP)

re_my_objdump : clean_my_objdump $(NAME_OBJDUMP)

clean_my_objdump : 
	$(RM) $(OBJ_OBJDUMP)

fclean_my_objdump : clean_my_objdump
	$(RM) $(NAME_OBJDUMP)

#ALL
fclean : fclean_my_nm fclean_my_objdump

re : re_my_objdump re_my_nm

all : $(NAME_NM) $(NAME_OBJDUMP)
