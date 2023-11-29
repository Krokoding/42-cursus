/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:21:10 by loris             #+#    #+#             */
/*   Updated: 2023/11/29 18:03:17 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char			*line_str;
	static t_list	*lst;
	t_list			*temp;

	if (BUFFER_SIZE <= 0 || read(fd, &line_str, 0) < 0 || fd < 0)
	{
		while (lst)
		{
			temp = (lst)->next;
			free((lst)->content);
			free(lst);
			lst = temp;
		}
		return (NULL);
	}
	creat_next_line(&lst, fd);
	if (lst == NULL)
		return (NULL);
	line_str = malloc(sizeof(char) * (ft_nextline(&lst, 0) + 1));
	if (!line_str)
		return (NULL);
	ft_lsttostr(&lst, line_str);
	ft_lstpropre(&lst);
	return (line_str);
}

int	ft_nextline(t_list **lst, int j)
{
	int		i;
	int		k;
	t_list	*temp;
	int		back_slash_inspector;

	back_slash_inspector = 0;
	temp = *lst;
	k = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
				return (++k);
			k++;
			if (temp->content[i] == '\0')
				back_slash_inspector = 1;
			if (back_slash_inspector == 0)
				j++;
			i++;
		}
		temp = temp->next;
	}
	return (j);
}

void	ft_lsttostr(t_list **lst, char *str)
{
	int		i;
	int		j;
	t_list	*temp;

	j = 0;
	temp = *lst;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if ((temp)->content[i] == '\n')
			{
				str[j] = '\n';
				j++;
				str[j] = '\0';
				return ;
			}
			str[j++] = (temp)->content[i++];
		}
		temp = temp->next;
	}
	str[j] = '\0';
}

void	ft_lstpropre(t_list **lst)
{
	t_list	*last_node;
	t_list	*new_node;
	char	*rest_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rest_buffer = malloc(BUFFER_SIZE + 1);
	if (!rest_buffer)
		return ;
	last_node = ft_lstder(*lst);
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] != '\0' && last_node->content[++i])
		rest_buffer[j++] = last_node->content[i];
	rest_buffer[j] = '\0';
	new_node = ft_lstnouv(rest_buffer);
	ft_free(lst, new_node, rest_buffer);
}

void	ft_free(t_list **lst, t_list *new_node, char *rest_buffer)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
	if (new_node->content[0])
		*lst = new_node;
	else
	{
		free(rest_buffer);
		free(new_node);
	}
}
