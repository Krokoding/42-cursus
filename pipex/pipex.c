/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:19:20 by loris             #+#    #+#             */
/*   Updated: 2023/11/24 16:39:48 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av)
{
	int fd[2];
	int	id;
	int	id2;

	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == 0)
		put_in_pipe(fd, av);
	else
	{
		id2 =fork();
		if (id2 == 0)
		{
			
			put_in_file(fd, av);
		}
		else
		{
			close(fd[0]);
			close(fd[1]);

			waitpid(id, NULL, 0);
			waitpid(id2, NULL, 0);
		}
	}
}

int	put_in_file(int	*fd, char **av)
{ 
	char	**command;
	char	*path;
	int		i;
	
	i = 0;
	command = ft_split(av[2], ' ');
	path = path_creator(command[0]);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
//	dup2(, STDOUT_FILENO);
	close(fd[0]);
	execve(path, command, NULL);
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	free(path);
	free(command);
}
int	put_in_pipe(int *fd, char **av)
{
	char 	**command;
	char 	*path;
	int		i;
	
	command = ft_split(av[1], ' ');
	path = path_creator(command[0]);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(path, command, NULL);
	i = 0;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	free(path);
	free(command);
}

char *path_creator(char *program_name)
{
	char	*str;
	int	i;
	int	j;
	
	j = 0;
	i = 5;
	str = malloc(sizeof(char) * (ft_strlen(program_name) + 6));
	str[0] = '/';
	str[1] = 'b';
	str[2] = 'i';
	str[3] = 'n';
	str[4] = '/';
	str[ft_strlen(program_name) + 5] = '\0';
	while (str[i])
	{
		str[i] = program_name[j];
		i++;
		j++;
	}
	return (str);
}