# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 21:13:39 by cjover-n          #+#    #+#              #
#    Updated: 2020/11/15 16:58:17 by cjover-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC =	ft_isalpha.c	ft_isprint.c	ft_strlcpy.c	ft_strrchr.c	\
		ft_atoi.c		ft_isascii.c	ft_strchr.c		ft_strlen.c		\
		ft_tolower.c	ft_isalnum.c	ft_isdigit.c	ft_strlcat.c	\
		ft_strncmp.c	ft_toupper.c	ft_memset.c		ft_bzero.c		\
		ft_memcpy.c		ft_memccpy.c	ft_memmove.c	ft_memchr.c		\
		ft_memcmp.c		ft_strnstr.c	ft_calloc.c		ft_strdup.c		\
		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	\
		ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_strmapi.c	\
		ft_itoa.c		ft_split.c		ft_lstiter.c	ft_strcdup.c	\
		ft_strnew.c		ft_putchar.c	ft_putnbr.c		ft_putstr.c		\
		ft_strcdup.c	get_next_line.c	ft_numlen.c		ft_isspace.c

SRCBONUS =	ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c \
		  	ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c ft_lstmap.c

DIRPRINTSRC =	ft_printf/

SRCPRINT =	ft_printf.c		ft_filler.c		ft_conversions.c	ft_zero.c	\
			ft_atoiprint.c	ft_flags.c		printf_utils.c	
			
ADDPRINT =	$(addprefix $(DIRPRINTSRC)/,$(SRCPRINT))

FLAGS = -Wextra -Wall -Werror -I

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

OBJPRINT = $(SRCPRINT:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(ADDPRINT) $(SRCBONUS) libft.h
	@gcc $(FLAGS)./ -c $(SRC) $(SRCBONUS) $(ADDPRINT) 
	@ar -rc $(NAME) $(OBJ) $(OBJBONUS) $(OBJPRINT)
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@rm -f *.out

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
