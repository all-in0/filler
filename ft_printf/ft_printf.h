/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:36:06 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 19:24:59 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 32
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "limits.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# define RED	write(1, "\x1b[31m", 5)
# define GRE	write(1, "\x1b[32m", 5)
# define YEL	write(1, "\x1b[33m", 5)
# define BLU	write(1, "\x1b[34m", 5)
# define MAG	write(1, "\x1b[35m", 5)
# define CYA	write(1, "\x1b[36m", 5)
# define EOC	write(1, "\x1b[0m", 4)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
    int				content;
    char			*save;
    struct s_gnl	*next;
}					t_gnl;

typedef struct		s_prf
{
	int				flags[5];
	int				width;
	int				prec;
	int				pr;
	int				length;
	char			spec;
	char			*str;
}					t_prf;

int                 get_next_line(const int fd, char **line);
int					kostuli(t_prf *phar);
char				*ft_strload(char *str, int a);
int					make_plus(t_prf *phar);
int					make_hesh(t_prf *phar);
int					make_space(t_prf *phar);
int					make_prec(t_prf *phar);
int					make_width(t_prf *phar);
int					length(const char *str, t_prf *phar);
int					prec(const char *str, t_prf *phar, va_list ap);
int					width(const char *str, t_prf *phar, va_list ap);
int					flags(const char *str, t_prf *phar);
int					test_symb(char c);
int					color(const char *s);
int					save_u(t_prf *phar, va_list ap);
int					save_b(t_prf *phar, va_list ap);
int					save_p(t_prf *phar, va_list ap);
int					save_o(t_prf *phar, va_list ap);
int					save_d(t_prf *phar, va_list ap);
int					save_c(t_prf *phar, va_list ap);
int					save_x(t_prf *phar, va_list ap);
int					save_s(t_prf *phar, va_list ap);
char				*ft_itoa_base_unsig(unsigned long long int value, int base);
char				*ft_a_itoa_base_unsig(unsigned long long int value,
					int base);
size_t				ft_big_s_strlen(wchar_t *s);
int					ft_printf(const char *format, ...);
char				*ft_ultoa(unsigned long long n);
char				*ft_itoa_base(long long value, int base, int up);
void				*ft_memset(void *str, int ch, size_t len);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t count);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *str1, const char *str2);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
size_t				ft_putchar(const uint32_t s);
void				ft_putstr(char *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char a, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
