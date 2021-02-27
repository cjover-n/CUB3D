# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 18:49:31 by cjover-n          #+#    #+#              #
#    Updated: 2021/02/27 12:41:17 by cjover-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = CUB3D

SRC =	main.c raycaster.c readmap.c rgbutils.c parsersmap.c errorhandler.c \
		cubutils.c movement.c player.c input.c textures.c	floodfill.c		\
		sprite.c

SRCLIB =	ft_isalpha.c	ft_isprint.c	ft_strlcpy.c	ft_strrchr.c	\
			ft_atoi.c		ft_isascii.c	ft_strchr.c		ft_strlen.c		\
			ft_tolower.c	ft_isalnum.c	ft_isdigit.c	ft_strlcat.c	\
			ft_strncmp.c	ft_toupper.c	ft_memset.c		ft_bzero.c		\
			ft_memcpy.c		ft_memccpy.c	ft_memmove.c	ft_memchr.c		\
			ft_memcmp.c		ft_strnstr.c	ft_calloc.c		ft_strdup.c		\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	\
			ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_strmapi.c	\
			ft_itoa.c		ft_split.c		ft_lstiter.c	ft_strcdup.c	\
			ft_strnew.c		ft_putchar.c	ft_putnbr.c		ft_putstr.c		\
			get_next_line.c	ft_numlen.c		ft_isspace.c	\
			ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	\
			ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c ft_lstmap.c

DIRLIBFTSRC = Libft/

DIRPRINTSRC =	Libft/ft_printf/

SRCPRINT =	ft_printf.c		ft_filler.c		ft_conversions.c	ft_zero.c	\
			ft_atoiprint.c	ft_flags.c		printf_utils.c

ADDLIBFT =	$(addprefix $(DIRLIBFTSRC)/,$(SRCLIB))

ADDPRINT =	$(addprefix $(DIRPRINTSRC)/,$(SRCPRINT))

FLAGS = -Wextra -Wall -Werror

MLX = -I ./ -I /usr/X11/include -g -I /usr/X11/lib -l mlx

MLXFLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) $(ADDLIBFT) $(ADDPRINT) Libft/libft.h
	@gcc $(MLX) $(MLXFLAGS) $(FLAGS) ./$(SRC) $(ADDLIBFT) $(ADDPRINT) -o CUB3D

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -f -r *.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
