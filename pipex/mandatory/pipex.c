/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:19:20 by loris             #+#    #+#             */
/*   Updated: 2023/12/05 09:29:44 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	id;

	if (ac != 5)
	{
		ft_putstr_fd("Execute like this :\n./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(0);
	}
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		exit(0);
	if (id == 0)
	{
		if (put_in_pipe(fd, av, envp) == -1)
			error_msg(av[1], "no such file or directory: ");
		if (!put_in_pipe(fd, av, envp))
			error_msg(av[2], "command not found: ");
	}
	else
	{
		if (!put_in_file(fd, av, envp))
			error_msg(av[3], "command not found: ");
	}
}

void	error_msg(char *cmd, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

int	put_in_pipe(int *fd, char **av, char **envp)
{
	int	fd_op;

	fd_op = open(av[1], O_RDONLY);
	if (fd_op == -1)
		return (-1);
	if (-1 == dup2(fd_op, STDIN_FILENO))
		return (-1);
	if (-1 == dup2(fd[1], STDOUT_FILENO))
		return (-1);
	if (!execute_command(av[2], envp))
		return (0);
	return (1);
}

int	put_in_file(int *fd, char **av, char **envp)
{
	int	fd_outfile;

	fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_outfile == -1)
		return (-1);
	close(fd[1]);
	if (-1 == dup2(fd[0], STDIN_FILENO))
		return (-1);
	if (-1 == dup2(fd_outfile, STDOUT_FILENO))
		return (-1);
	if (!execute_command(av[3], envp))
		return (0);
	return (1);
}

int	norme_execute_command(char *path, char **command, char *command_slash)
{
	if (execve(path, command, NULL) == -1)
	{
		free(command_slash);
		free_tab(command);
		free(path);
		return (-1);
	}
	return (1);
}
