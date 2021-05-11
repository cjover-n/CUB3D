# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 18:49:31 by cjover-n          #+#    #+#              #
#    Updated: 2021/05/11 14:22:14 by cjover-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	main.c raycaster.c readmap.c messages.c mapparser.c errorhandler1.c \
		errorhandler2.c movement.c player.c input.c textures.c	floodfill.c	\
		sprites1.c sprites2.c destroy.c screenshot.c mapcheck.c texturecheck.c \
		cubutils.c resparser.c

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

R = $(shell printf "\033[31m")
G = $(shell printf "\033[32m")
B = $(shell printf "\033[34m")
X = $(shell printf "\033[0m")
Y = $(shell printf "\033[33m")

DIRLIBFTSRC = Libft/

ADDLIBFT = $(addprefix $(DIRLIBFTSRC),$(SRCLIB))
SRCOBJ = $(SRC:.c=.o) $(ADDLIBFT:.c=.o)

#CFLAGS = -Wextra -Wall -Werror -I ./

#MLX = -l mlx

CFLAGS = -Wextra -Wall -Werror -I ./ -I /usr/X11/include -g #-g3 -fsanitize=address

MLX = -L /usr/X11/lib -l mlx

MLXFLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) $(SRCOBJ) Libft/libft.h
	@gcc $(MLX) $(MLXFLAGS) $(SRCOBJ) $(CFLAGS) -o cub3D
	@echo ${Y}==== CUB COMPILADO CORRECTAMENTE ==========${X}
	@echo ${G}==== AHORA EJECTUTA ${R}cub3D ${G}SEGUIDO DE UN MAPA ${R}.cub ${G}====${X}
	@echo ${G}==== USA ${B}--save ${G}COMO 3ER PARÁMETRO PARA OBTENER UN SCREENSHOT ====${X}

clean:
	@rm -f *.o
	@rm -f $(DIRLIBFTSRC)*.o
	@rm -f screenshot.bmp
	@rm -f *.out
	@rm -f -r *.dSYM

fclean: clean
	@rm -f $(NAME)
	@echo ${B}=========== CUB LIMPIO, CUB CONTENTO ===========${X}

re: fclean all

pizza:
	@echo ${Y}"Sin piña, por favor :)"${X}

love:
	@echo ${R}"<3 Love is in the air <3"${X}

tig:
	@echo ${B}"NO DEBERÍAS!! ¬¬"${X}

.PHONY: all clean fclean re
