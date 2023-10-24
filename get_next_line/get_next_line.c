/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:21:10 by loris             #+#    #+#             */
/*   Updated: 2023/10/24 14:40:37 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line_str;
	static t_list	*lst;
	int				n;
	char			c;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	n = read(fd, buff, BUFFER_SIZE);
	c = n + '0';
	if (n <= 0)
		return (NULL);
	buff[n] = '\0';
	while (ft_lst_check(&lst))
		ft_lstadd_back(&lst, ft_lstnew(buff));
	line_str = malloc(sizeof(char) * ft_nextline(&lst));
	if (!line_str)
		return (NULL);
	ft_lsttostr(&lst, line_str);
	ft_lstclear(lst);
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
		temp = (temp)->next;
	}
}

void	ft_lstclear(t_list *lst)
{
	t_list	*last_node;
	t_list	*new_node;
	int		i;
	int		j;

	i = 0;
	j = 0;
	last_node = malloc(sizeof(t_list));
	if (!new_node || !last_node)
		return ;
	last_node = ft_lstlast(lst);
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[i] != '\n')
		new_node->content[j++] = last_node->content[i++];
	new_node->content[j] = '\0';
	ft_free(lst, new_node);
}

void	ft_free(t_list *lst, t_list *new_node)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = (lst)->next;
		free(lst);
		lst = temp;
	}
	ft_lstadd_back(&lst, new_node);
}

int main() {
    int fd = open("exemple.txt", O_RDONLY); // Ou utiliser 0 pour l'entrée standard (stdin)
    char *line;


    while ((line = get_next_line(fd)) != NULL) {
        // Faites quelque chose avec la ligne, par exemple l'imprimer
        printf("%s", line);
        // Libérez la mémoire allouée pour la ligne après utilisation
        free(line);
    }

    // Fermez le descripteur de fichier une fois que vous avez fini de lire
    close(fd);
    return 0;
}