/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:21:10 by loris             #+#    #+#             */
/*   Updated: 2023/10/24 10:52:52 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>>
#include "get_next_line.h"



char	*get_next_line(int fd)
{
	char			*buff;
	char			*line_str;
	static t_list	**lst;
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_nextline)
	{
		buff[BUFFER_SIZE] = '\0';
		ft_lstadd_back(lst, ft_lstnew(buff));
	}
	line_str = malloc(sizeof(char) * ft_nextline(lst));
	line_str = ft_lsttostr(lst, ft_nextline(lst));
	ft_lstclear(lst);
	return(line_str);
}

int	ft_nextline(t_list **lst)
{
	int	i;
	int	k;
	
	k = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
				return (k);
			k++;
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

int	ft_lsttostr(t_list **lst, char *str, int size)
{
	int	i;
	int	j;
	
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			str[j] = lst->content[i];
			if (lst->content[i] == '\n')
			{
				str[++j] = '\0';
				str[j] = '\n';
				return ;
			}
			i++;
			j++;
		}
		lst = lst->next;
	}
}

void	*ft_lstclear(t_list **lst)
{
	t_list	*last_node;
	t_list	*new_node;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	last_node = malloc(sizeof(t_list));
	new_node = malloc(sizeof(t_list));
	if (!new_node || !last_node)
		return (0);
	last_node = ft_lstlast(lst);
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[i] != '\n')
		new_node->content[j++] = last_node->content[i++];
	new_node->content[j] = '\0';
	ft_free(lst, new_node);
}
void	*ft_free(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	ft_lstadd_back(lst, new_node);
}