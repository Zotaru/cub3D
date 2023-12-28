/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:19:32 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 18:05:07 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
// # include <io.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>

# include "ft_printf.h"

void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *string);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc( size_t elementCount, size_t elementSize);
char	*ft_strdup(char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);

// ft_lst 
typedef struct int_list
{
	int				content;
	struct int_list	*next;
}					t_ilist;

t_ilist	*ft_lstnew(int content);
void	ft_lstadd_front(t_ilist **lst, t_ilist *new);
int		ft_lstsize(t_ilist *lst);
t_ilist	*ft_lstlast(t_ilist *lst);
void	ft_lstadd_back(t_ilist **lst, t_ilist *new);
void	ft_lstdelone(t_ilist *lst, void (*del)(int));
void	ft_lstclear(t_ilist **lst, void (*del)(int));
void	ft_lstiter(t_ilist *lst, void (*f)(int));
t_ilist	*ft_lstmap(t_ilist *lst, int (*f)(int), void (*del)(int));

// ft_gnl

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_listnew(char *content, t_list *lst, int j);
void	ft_listadd_back(t_list **lst, t_list *new, int i);
int		ft_listiter(t_list *lst, int (*f)(char *, char, int));
char	*get_next_line(int fd);
char	*ft_fill_from_lst(t_list *lst);
int		ft_check_sep(char *s, char c, int boolean);
char	*ft_normi(char *kanye, char *buffer, t_list **lst, int *tab_fd_l);
char	*length_diff_zero(char *buf, char *kanye, int length, t_list **lst);
t_list	*get_next_line2(int fd);
char	*ret_line_in_static2(char *kanye, t_list **lst);

#endif
