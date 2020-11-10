gcc -I ./ -I /usr/X11/include -g -L /usr/X11/lib -L ./Libft/ -lft -l mlx -framework OpenGL -framework AppKit main.c init.c readmap.c
./a.out map.cub