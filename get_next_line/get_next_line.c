/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:21:10 by loris             #+#    #+#             */
/*   Updated: 2023/10/24 18:12:00 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line_str;
	static t_list	*lst;
	int				n;

	while (ft_lst_check(&lst))
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		n = read(fd, buff, BUFFER_SIZE);
		if (!buff)
		{
			free(buff);
			return (NULL);
		}
		if (n <= 0)
			return (NULL);
		ft_lstadd_back(&lst, ft_lstnew(buff));
	}
	line_str = malloc(sizeof(char) * ft_nextline(&lst));
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
				return (++k);
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
			if ((temp)->content[i] == '\n')
			{
				str[++j] = '\0';
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
	while (last_node->content[i] && last_node->content[i] != '\n')
		rest_buffer[j++] = last_node->content[i++];
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
		free(rest_buffer);
		free(new_node);
	}
}

int main() {
    int fd = open("exemple.txt", O_RDONLY); // Ou utiliser 0 pour l'entrée standard (stdin)
    char *line;


    line = get_next_line(fd);
	printf("%s\n", line);
    line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
    line = get_next_line(fd);
	printf("%s\n", line);
    close(fd);
    return 0;
}