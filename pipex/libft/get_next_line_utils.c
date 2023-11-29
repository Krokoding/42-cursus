/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:20:38 by loris             #+#    #+#             */
/*   Updated: 2023/11/29 18:01:27 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnouv(char *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!content)
		return (NULL);
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_der(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstder(*lst);
			temp->next = new;
		}
		new->next = NULL;
	}
}

t_list	*ft_lstder(t_list *lst)
{
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

int	ft_lst_check(t_list **lst)
{
	int		i;
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		i = 0;
		while (temp->content[i] && i < BUFFER_SIZE)
		{
			if (temp->content[i] == '\n')
				return (0);
			i++;
		}
		temp = temp->next;
	}
	return (1);
}

void	creat_next_line(t_list **lst, int fd)
{
	char			*buff;
	int				n;

	while (ft_lst_check(lst))
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		n = read(fd, buff, BUFFER_SIZE);
		if (n <= 0)
		{
			free(buff);
			return ;
		}
		buff[n] = '\0';
		ft_lstadd_der(lst, ft_lstnouv(buff));
	}
}
