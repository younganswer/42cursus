/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:35:31 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/02 14:48:06 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

// Part 1 - Libc functions
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t sz_);
size_t			ft_strlcat(char *dest, const char *src, size_t sz_);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *s, const char *target, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t sz_);
char			*ft_strdup(const char *str);

// Part 2 - Additional functions
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(const char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

// Bonus
typedef struct s_list_libft
{
	void				*content;
	struct s_list_libft	*next;
}	t_list_libft;

t_list_libft	*ft_lstnew(void *content);
void			ft_lstadd_front(t_list_libft **lst, t_list_libft *new);
int				ft_lstsize(t_list_libft *lst);
t_list_libft	*ft_lstlast(t_list_libft *lst);
void			ft_lstadd_back(t_list_libft **lst, t_list_libft *new);
void			ft_lstdelone(t_list_libft *lst, void (*del)(void *));
void			ft_lstclear(t_list_libft **lst, void (*del)(void *));
void			ft_lstiter(t_list_libft *lst, void (*f)(void *));
t_list_libft	*ft_lstmap(t_list_libft *lst, \
							void *(*f)(void *), void (*del)(void *));

// Custom type to use
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

// Custom functions to use
void			ft_exit_with_error(const char *str, const int exit_flag);
t_bool 			ft_is_space(const int c);

#endif