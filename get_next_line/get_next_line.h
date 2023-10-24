/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:30:44 by loris             #+#    #+#             */
/*   Updated: 2023/10/24 18:09:55 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
char	*get_next_line(int fd);
int		ft_nextline(t_list **lst);
void	ft_lsttostr(t_list **lst, char *str);
void	ft_lstclear(t_list **lst);
void	ft_free(t_list **lst, t_list *new_node, char *rest_buffer);
int		ft_lst_check(t_list **lst);
char	*ft_strdup(char *source);


#endif
