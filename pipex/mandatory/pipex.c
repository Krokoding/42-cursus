/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:19:20 by loris             #+#    #+#             */
/*   Updated: 2023/11/28 19:53:04 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	int fd[2];
	int	id;

	if (ac != 5)
	{
		ft_putstr_fd("Need 4 arg\n", 2);
		exit(0);
	}	
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		exit(0);
	if (id == 0)
	{
		if (!put_in_pipe(fd, av, envp))
		{
			ft_putstr_fd("Exec the program like this :\n./pipex file1 cmd1 cmd2 file2\n", 2);
			exit(0);
		}
		if (-1 == put_in_pipe(fd, av, envp))
		{
			ft_putstr_fd("asalamalecum\n", 2);
			exit(0);
		}
	}
	else
	{
		if (!put_in_file(fd, av, envp))
		{
			ft_putstr_fd("Exec the program like this :\n./pipex file1 cmd1 cmd2 file2\n", 2);
			exit(0);
		}
	}
}

int	put_in_pipe(int *fd, char **av, char **envp)
{
	char 	**command;
	char 	*path;
	int		fd_op;
	
	fd_op = open(av[1], O_RDONLY);
	if (fd_op == -1)
		return (-1);
	command = ft_split(av[2], ' ');
	if (path_creator(cmd_slash(command[0]), envp, "PATH") == 0)
	{
		free_tab(command);
		return (0);
	}
	path = path_creator(cmd_slash(command[0]), envp, "PATH");
	dup2(fd_op, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execve(path, command, NULL);
	free_tab(command);
	free(path);
	return (1);
}

int	put_in_file(int	*fd, char **av, char **envp)
{ 
	char	**command;
	char	*path;
	int		fd_outfile;

	fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	command = ft_split(av[3], ' ');
	if (path_creator(cmd_slash(command[0]), envp, "PATH") == 0)
	{
		free_tab(command);
		return (0);
	}
	path = path_creator(cmd_slash(command[0]), envp, "PATH");
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	execve(path, command, NULL);
	free_tab(command);
	free(path);
	return (1);
}
