/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:32:58 by loris             #+#    #+#             */
/*   Updated: 2023/11/28 11:25:06 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

int			ft_strisdigit(char *str);
long int	ft_atoli(const char *nptr);
double		ft_atof(const char *str);
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
int			ft_size_b(int nb);

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
char		*ft_itoab(int n, int size);
char    	*ft_strjoinsep(char *a, char *b, char sep);

size_t		ft_strlcpy(char *destination, const	char *source, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// GNL

t_list		*ft_lstder(t_list *lst);
t_list		*ft_lstnouv(char *content);

void		creat_next_line(t_list **lst, int fd);
void		ft_lstadd_der(t_list **lst, t_list *new);
void		ft_lsttostr(t_list **lst, char *str);
void		ft_lstpropre(t_list **lst);
void		ft_free(t_list **lst, t_list *new_node, char *rest_buffer);

char		*next_line(int fd, t_list	*lst);
char		*get_next_line(int fd);

int			ft_nextline(t_list **lst, int j);
int			ft_lst_check(t_list **lst);

// PRINTF

int			print_type_redirector(char c, va_list args);
int			ft_print_char(char c);
int			ft_print_str(char *str);
int			ft_printf(const char *str_to_print, ...);
char		*ft_uitoa(unsigned int n);
int			ft_print_uint(unsigned int n);
int			ft_print_base(unsigned int nb, int base);
char		*ft_itoa_base(unsigned int n, char *base);
int			ft_size_base(unsigned int nb);
int			ft_print_decimal(int nb);
int			ft_print_base_p(unsigned long long nb);
char		*ft_itoa_base_p(uintptr_t n, char *base);
int			ft_size_base_p(uintptr_t nb);
int			write_polemik(const char *str_to_print,
				va_list args, int i, int count);
#endif