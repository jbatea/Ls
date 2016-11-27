# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbateau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 14:55:10 by jbateau           #+#    #+#              #
#    Updated: 2016/04/30 19:02:26 by jbateau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -Wall -Wextra -Werror -I../includes

SRC =	ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbrl.c \
	  ft_putnbr.c \
	  ft_putendl.c \
	  ft_strlen.c \
	  ft_abs.c \
	  ft_isalpha.c \
	  ft_ishex.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strdup.c \
	  ft_strdup_free.c \
	  ft_strndup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strchr_cnt.c \
	  ft_strcmp.c \
	  ft_strscmp.c \
	  ft_strncmp.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_xtoi.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strclr.c \
	  ft_strlcat.c \
	  ft_memalloc.c \
	  ft_strnew.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strnjoin.c \
	  ft_strjoin_free.c \
	  ft_strtrim.c \
	  ft_memdel.c \
	  ft_strdel.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_itoa.c \
	  ft_ltoa.c \
	  ft_lltoa.c \
	  ft_stoa.c \
	  ft_lltoo.c \
	  ft_itox.c \
	  ft_lltob.c \
	  ft_strsplit.c \
	  ft_sizestring.c \
	  ft_countstring.c \
	  ft_count.c \
	  ft_isupper.c \
	  ft_islower.c \
	  ft_strtrimall.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstnew.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  get_next_line.c \
	  ft_sduporjoin.c \
	  ft_snduporjoin.c \
	  ft_printf.c \
	  ft_specret.c \
	  ft_listinit.c \
	  ft_newelem.c \
	  ft_isspecifier.c \
	  ft_whichspec.c \
	  ft_isflag.c \
	  ft_speccnt.c \
	  ft_checkformat.c \
	  ft_eolflag.c \
	  ft_lflag.c \
	  ft_printarg.c \
	  ft_patype.c \
	  ft_printlist.c \
	  ft_isstr.c \
	  ft_elemspec.c \
	  ft_strlower_free.c \
	  ft_validflags.c \
	  ft_normtmp.c \
	  ft_whichflags.c \
	  ft_applyflag.c \
	  ft_sharpflag.c \
	  ft_signflag.c \
	  ft_basicflags.c \
	  ft_islenflag.c \
	  ft_orderflags.c \
	  ft_precchr.c \
	  ft_lenchr.c \
	  ft_leftalig.c \
	  ft_fillflag.c \
	  ft_flagpriority.c \
	  ft_rightalig.c \
	  ft_leftflagchr.c \
	  ft_precflag.c \
	  ft_lenmod.c \
	  ft_pamodtype.c \
	  ft_pamodind.c \
	  ft_pamodx.c \
	  ft_lststrlen.c \
	  ft_lstfree.c \
	  ft_eolspec.c \
	  ft_checkflags.c \
	  ft_dtos.c \
	  ft_isbspec.c \
	  ft_snotation.c \
	  ft_doubleprec.c \
	  ft_dprecsci.c \
	  ft_ispoint.c \
	  ft_islennorm.c \
	  ft_sharpnfill.c \
	  ft_patypefloat.c \
	  ft_applypa.c \
	  ft_countdouble.c \
	  ft_lenandprec.c \
	  ft_cnt.c \
	  ft_tablen.c \
	  ft_initlongtab.c \
	  ft_unbehaviour.c \
	  ft_applylenmod.c \
	  ft_lenfourafive.c \
	  ft_sizeb.c \
	  ft_wctos.c \
	  ft_putstrnull.c \
	  ft_increaselen.c \
	  ft_isspace.c \
	  ft_litox.c \
	  ft_llitox.c \
	  ft_flagorder.c \
	  ft_iss.c \
	  ft_lenandzero.c \
	  ft_applysharp.c \
	  ft_pacnull.c \
	  ft_freeall.c \
	  ft_iscnull.c \
	  ft_llutoa.c \
		ft_intchr.c \
		ft_tabfree.c \

SRCC = $(patsubst %.c,srcs/%.c,$(SRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(SRCC) -c
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
