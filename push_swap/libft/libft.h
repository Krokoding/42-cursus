/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:32:58 by loris             #+#    #+#             */
/*   Updated: 2023/11/14 11:10:13 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_memcmp(const void *pointer1, const void *pointer2, size_t size);
int			ft_strncmp(const char *first, const char *second, size_t length );
int			ft_strlen(const char *str);
int			ft_atoi(const char *nptr);
int			ft_isprint(int c);
int			ft_isdigit(char c);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_lstsize(t_list *lst);
int			ft_isalnum(int c);
int			ft_size_base(unsigned int nb);

long int	ft_atoli(const char *nptr);

void		ft_putnbr_fd(int nb, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		*ft_memset(void *pointer, int value, size_t count);
void		*ft_memmove(void *dest, const void *src, size_t count);
void		*ft_memcpy(void *destination, const void *source, size_t size);
void		*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
void		*ft_calloc(size_t elementCount, size_t elementSize);
void		ft_bzero(void *str, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strrchr(const char *string, int searchedChar);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *source);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *string, int searchedChar);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_itoa_binary(int n);

size_t		ft_strlcpy(char *destination, const	char *source, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif