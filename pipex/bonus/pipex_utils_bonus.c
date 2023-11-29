/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:59:55 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/29 12:13:54 by lkary-po         ###   ########.fr       */
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
