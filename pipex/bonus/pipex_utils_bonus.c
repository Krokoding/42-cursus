/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:59:55 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/05 09:19:34 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_utils_creator(int i, int ac, char **av, char **envp)
{
	while (i < ac - 2)
	{
		if (!pipe_creator(envp, av[i]))
			error_msg(av[i], "command not found: ");
		i++;
	}
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
