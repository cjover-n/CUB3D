/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:37:31 by cjover-n          #+#    #+#             */
/*   Updated: 2020/10/17 19:06:37 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct		s_tab
{
	const char		*s;
	int				arr;
	va_list			list;
	int				len;
	int				f_hyphen;
	int				f_plus;
	int				f_astsk;
	int				f_dot;
	int				f_pad;
	int				f_zero;
	int				f_space;
	int				f_percent;
	int				r;
	int				l;
	int				num;
	int				width;
	int				f_miki;
	int				f_igor;
	char			*itoa_ret;
	long long int	itoa_n;
	int				itoa_pos;
	int				itoa_base;
	int				itoa_neg;
	int				f_null;
	int				f_control;
	int				f_signpointer;
	int				final_i;
}					t_tab;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int n);
int				ft_isalnum(int n);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t maxlen);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strchr(const char *s, int c);
char			*ft_strncpy(char *dst, const char *src, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			**ft_split(char const *str, char charset);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
char			*ft_strcdup(const char *s1, int c);
char			*ft_strnew(size_t size);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
char			*ft_strcdup(const char *s1, int c);
int				get_next_line(int fd, char **line);
int				ft_printf(const char *format, ...);
void			ft_putchar_print(t_tab *c, const char d);
void			ft_putstr_pre(t_tab *c, const char *str);
void			ft_putstr_print(t_tab *c, const char *str);
void			ft_initialize(t_tab *c);
void			ft_flags1(t_tab *c);
void			ft_flags2(t_tab *c);
void			ft_flags3(t_tab *c);
void			ft_types(t_tab *c);
int				ft_atoi_print(t_tab *c);
char			*ft_itoabase(t_tab *c);
void			*ft_itoabase_logic(t_tab *c);
void			ft_c(t_tab *c);
void			ft_s(t_tab *c);
void			ft_id(t_tab *c);
void			ft_do_hyphen(t_tab *c);
void			ft_width(t_tab *c);
void			ft_igor(t_tab *c, char *str);
void			ft_coco(t_tab *c, char *str);
void			ft_miki(t_tab *c);
void			ft_alex(t_tab *c);
void			ft_hexadecimal(t_tab *c, const char *str);
void			ft_bonus(t_tab *c);


#endif
