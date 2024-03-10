/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:22:46 by solee2            #+#    #+#             */
/*   Updated: 2023/06/02 10:21:09 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *dst, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
int		ft_isalnum(char input);
int		ft_isalpha(char letter);
int		ft_isascii(int input);
int		ft_isdigit(char input);
int		ft_isprint(int input);
char	*ft_itoa(int n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *strone, const void *strtwo, size_t n);
void	*ft_memcpy(void *dest, const void *original, size_t n);
void	*ft_memmove(void *dest, void *source, size_t n);
void	*ft_memset(void *str, int value, size_t number);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *str, char set);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *target, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	ft_tolower(int initial);
char	ft_toupper(int intitial);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*get_next_line(int fd);
char	*file_reader(int fd, char *result);
char	*getting_line(char *buffer);
char	*getting_next_line(char *buffer);
char	*join_free(char *result, char *buffer);

char	*gnl_ft_strjoin(char *s1, char *s2);
void	*gnl_ft_memset(void	*str, int value, size_t number);
char	*gnl_ft_strchr(const char *str, int c);
void	*gnl_ft_calloc(size_t nitems, size_t size);
size_t	gnl_ft_strlen(const char *str);

#endif
