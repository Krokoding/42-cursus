/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:04 by loris             #+#    #+#             */
/*   Updated: 2023/11/29 18:11:38 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	fd_start;
	int	fd_end;

	if (ac < 5)
		exit (0);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		fd_end = open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		open_here_doc(av);
		i = 3;
	}
	else
	{
		i = 2;
		fd_start = open(av[1], O_RDONLY);
		fd_end = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dup2(fd_start, 0);
	}
	if (fd_end == -1 || fd_start == -1)
		return (0);
	pipex_utils_creator(i, ac, av, envp);
	dup2(fd_end, STDOUT_FILENO);
	if (!execute_command(av[ac - 2], envp))
		error_msg(av[ac - 2], "command not found: ");
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
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str || ((ft_strlen(str) == ft_strlen(av[2]) + 1) && (ft_strncmp(str, av[2], ft_strlen(av[2])) == 0)))
		{
			free(str);
			exit(0);
		}
		ft_putstr_fd(str, fd[1]);
		free(str);
	}
}

int	pipe_creator(char **env, char *av)
{
	int		fd[2];
	int		id;

	if (pipe(fd) == -1)
		return (0);
	id = fork();
	if (id == -1)
		exit (0);
	if (!id)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (!execute_command(av, env))
			return (0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	return (1);
}

int	execute_command(char *av, char **envp)
{
	char	*command_slash;
	char	*path;
	char	**command;

	command = ft_split(av, ' ');
	if (!command)
		return (0);
	command_slash = cmd_slash(command[0]);
	if (!command_slash)
		return (0);
	path = path_creator(command_slash, envp, "PATH");
	if (!path)
		return (0);
	if (-1 == execve(path, command, NULL))
	{
		free(command_slash);
		free_tab(command);
		free(path);
		return (0);
	}
	return (1);
}
