/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 11:59:35 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/17 17:49:41 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <lists.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <vector.h>

/*
** Characters
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** IO
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);

/*
** Memory
*/
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/*
** Strings
*/
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				checkchar(char c, char *comparison);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_lstrchr(const char *s, int c, int len);

/*
** Additional String Functions
*/
char			**ft_free(char **strs);
char			**ft_split(char const *s, char c);
double			ft_atod(char *str);
long			ft_atol(const char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

/*
** Utility
*/
int				ft_pow(int base, int power);
int				ft_intlen(int n);

/*
** Get Next Line
*/
# define BUFFER_SIZE 32

char			*get_next_line(int fd);

typedef struct s_gnl
{
	t_vector	*line;
	char		buff[BUFFER_SIZE];
	int			length;
}				t_gnl;

typedef struct s_concat
{
	size_t		size;
	char		*new;
	int			i;
	int			j;
	int			found;
}				t_concat;

#endif
