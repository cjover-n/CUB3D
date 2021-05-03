# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 18:49:31 by cjover-n          #+#    #+#              #
#    Updated: 2021/05/03 19:55:54 by cjover-n         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	main.c raycaster.c readmap.c messages.c mapparser.c errorhandler.c \
		cubutils.c movement.c player.c input.c textures.c	floodfill.c		\
		sprites1.c sprites2.c destroy.c screenshot.c mapcheck.c

SRCLIB =	ft_isalpha.c	ft_isprint.c	ft_strlcpy.c	ft_strrchr.c	\
			ft_atoi.c		ft_isascii.c	ft_strchr.c		ft_strlen.c		\
			ft_tolower.c	ft_isalnum.c	ft_isdigit.c	ft_strlcat.c	\
			ft_strncmp.c	ft_toupper.c	ft_memset.c		ft_bzero.c		\
			ft_memcpy.c		ft_memccpy.c	ft_memmove.c	ft_memchr.c		\
			ft_memcmp.c		ft_strnstr.c	ft_calloc.c		ft_strdup.c		\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	\
			ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_strmapi.c	\
			ft_itoa.c		ft_split.c		ft_strcdup.c	ft_isspace.c	\
			ft_strnew.c		ft_putchar.c	ft_putnbr.c		ft_putstr.c		\
			get_next_line.c	ft_numlen.c

DIRLIBFTSRC = Libft/

ADDLIBFT =	$(addprefix $(DIRLIBFTSRC)/,$(SRCLIB))

FLAGS = -Wextra -Wall -Werror

MLX = -I ./ -I /usr/X11/include -g -L /usr/X11/lib -l mlx

MLXFLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) $(ADDLIBFT) Libft/libft.h
	@gcc $(MLX) $(MLXFLAGS) $(FLAGS) ./$(SRC) $(ADDLIBFT) -o cub3D
	@echo ========= PROGRAMA RECOMPILADO ========

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -f -r *.dSYM

fclean: clean
	@rm -f $(NAME)
	@echo =========== PROGRAMA LIMPIO ===========

re: fclean all

.PHONY: all clean fclean re
