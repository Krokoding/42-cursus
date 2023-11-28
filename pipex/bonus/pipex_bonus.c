/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:04 by loris             #+#    #+#             */
/*   Updated: 2023/11/28 22:08:21 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av, char **envp)
{
	int i;
	int fd_start;
	int fd_end;
	char **command;
	char *path;

	if (ac < 5)
		exit (0);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		fd_end = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		open_here_doc(av);
		i = 3;
	}
	else
	{
		i = 2;
		ft_printf("okkkkk");
		fd_start = open(av[1], O_RDONLY);
		fd_end = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dup2(fd_start, 0);
	}
	while(i < ac - 2)
		pipe_creator(envp, av[i++]);
	dup2(fd_end, STDOUT_FILENO);
	command = ft_split(av[ac - 2], ' ');
	path = path_creator(cmd_slash(command[0]), envp, "PATH");
	execve(path, command, NULL);
}

int	open_here_doc(char **av)
{
	int	fd[2];
	int	id;
	
	if (pipe(fd) == -1)
		return (0);
	id = fork();
	if (!id)
		here_doc(av, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	return (0);
}

int	here_doc(char **av, int *fd)
{
	char *str;

	while(1)
	{
		str = get_next_line(0);
		if (ft_strncmp(str, av[2], ft_strlen(av[2])) == 0)
		{
			free(str);
			exit(0);
		}
		ft_putstr_fd(str, fd[1]);
		free(str);
	}
}

int pipe_creator(char **env, char *av)
{
	int     fd[2];
	int     id;
	char    **command;
	char    *path;

	if (pipe(fd) == -1)
		return (0);
	id = fork();
	if (id == -1)
		exit (0);
	if (!id)
	{
		command = ft_split(av, ' ');
		path = path_creator(cmd_slash(command[0]), env, "PATH");
		ft_printf("%s\n", path);
		close(fd[0]);
		dup2(fd[1], 1);
		execve(path, command, NULL);
		free_tab(command);
		free(path);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	return (0);
}