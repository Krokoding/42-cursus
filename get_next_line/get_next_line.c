/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:21:10 by loris             #+#    #+#             */
/*   Updated: 2023/10/25 14:43:52 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	creat_next_line(t_list **lst, int fd)
{
	char			*buff;
	int				n;

	while (ft_lst_check(lst))
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
		{
			free(buff);
			return ;
		}
		n = read(fd, buff, BUFFER_SIZE);
		buff[n] = '\0';
		if (n <= 0)
		{
			free(buff);
			return ;
		}
		ft_lstadd_back(lst, ft_lstnew(buff));
	}
}

char	*get_next_line(int fd)
{
	char			*line_str;
	static t_list	*lst;

	if (BUFFER_SIZE <= 0 || read(fd, &line_str, 0) < 0 || fd < 0)
		return (NULL);
	creat_next_line(&lst, fd);
	if (lst == NULL)
		return (NULL);
	line_str = malloc(sizeof(char) * (ft_nextline(&lst) + 1));
	if (!line_str)
		return (NULL);
	ft_lsttostr(&lst, line_str);
	ft_lstclear(&lst);
	return (line_str);
}

int	ft_nextline(t_list **lst)
{
	int		i;
	int		k;
	t_list	*temp;

	temp = *lst;
	k = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
			{
				k++;
				return (k);
			}
			k++;
			i++;
		}
		temp = temp->next;
	}
	return (k);
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
			if ((temp)->content[i] == '\n' || (temp)->content[i] == '\0')
			{
				str[j] = '\0';
				j++;
				str[j] = '\n';
				return ;
			}
			str[j] = (temp)->content[i];
			i++;
			j++;
		}
		temp = temp->next;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*last_node;
	t_list	*new_node;
	char	*rest_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rest_buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!new_node || !rest_buffer)
		return ;
	last_node = ft_lstlast(*lst);
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] != '\0' && last_node->content[++i] != '\n')
		rest_buffer[j++] = last_node->content[i];
	rest_buffer[j] = '\0';
	new_node = ft_lstnew(rest_buffer);
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
		*lst = NULL;
		free(rest_buffer);
		free(new_node);
	}
}

int main()
{
    int fd;
    char *line;

    fd = open("exemple.txt", O_RDONLY);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
