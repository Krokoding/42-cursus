/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:19:20 by loris             #+#    #+#             */
/*   Updated: 2023/11/27 15:01:34 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av)
{
	int **fd;
	int	id;
	int	id2;
	int	id3;
	
	ac++;
	fd = malloc(sizeof(int *) * 2);
	fd[0] = malloc(sizeof(int) * 2);
	fd[1] = malloc(sizeof(int) * 2);
	if (pipe(fd[0]) == -1)
		return (1);

	id = fork();
	if (id == 0)
		cat_first_file(fd, av);
	else
	{
		if (pipe(fd[1]) == -1)
			return (1);
		id2 = fork();
		if (id2 == 0)
			put_in_pipe(fd, av);
		else
		{

			id3 = fork();
			if (id3 == 0)
				put_in_file(fd, av);
			else
			{
				close(fd[0][0]);
				close(fd[0][1]);
				close(fd[1][0]);
				close(fd[1][1]);
				waitpid(id, NULL, 0);
				waitpid(id2, NULL, 0);
				waitpid(id3, NULL, 0);
			}
		}
	}
}

int	cat_first_file(int **fd, char **av)
{
	char	**arg_cat;
	arg_cat = malloc(sizeof(char *) * 3);
	
	arg_cat[0] = malloc(sizeof(char) * ft_strlen(av[1]));
	arg_cat[1] = malloc(sizeof(char) * 4);
	arg_cat[2] = NULL;
	
	arg_cat[0] = "cat";
	arg_cat[1] = av[1];
	arg_cat[2] = NULL;
	
	close(fd[0][0]);
	dup2(fd[0][1], STDOUT_FILENO);
	close(fd[0][1]);
	execve("/bin/cat", arg_cat, NULL);
	free(arg_cat[0]);
	free(arg_cat);
	return (0);
}

int	put_in_pipe(int **fd, char **av)
{
	char 	**command;
	char 	*path;
	int		i;

	command = ft_split(av[2], ' ');
	ft_printf("%s\n", command[1]);
	path = path_creator(command[0]);
	close(fd[0][1]);
	dup2(fd[0][0], STDIN_FILENO);
	close(fd[0][0]);
	close(fd[1][0]);
	dup2(fd[1][1], STDOUT_FILENO);
	close(fd[1][1]);
	execve(path, command, NULL);
	i = 0;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	free(path);
	free(command);
	return (0);
}

int	put_in_file(int	**fd, char **av)
{ 
	char	**command;
	char	*path;
	int		i;
	int		fd_outfile;

	fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	i = 0;
	command = ft_split(av[3], ' ');
	path = path_creator(command[0]);
	close(fd[1][1]);
	dup2(fd[1][0], STDIN_FILENO);
	close(fd[1][0]);
	dup2(fd_outfile, STDOUT_FILENO);
	execve(path, command, NULL);
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	free(path);
	free(command);
	return (0);
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
	str[i] = 'd';
	while (str[i])
	{
		str[i] = program_name[j];
		i++;
		j++;
	}
	return (str);
}