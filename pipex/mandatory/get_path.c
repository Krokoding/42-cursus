/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:48:05 by loris             #+#    #+#             */
/*   Updated: 2023/11/29 15:01:51 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_creator(char *cmd, char **env, char *pathvar)
{
	char	*allpath;
	char	**different_path;
	int		i;
	char	*str;

	allpath = find_in_envp(env, pathvar);
	i = 0;
	different_path = ft_split(allpath, ':');
	while (different_path[i])
	{
		str = ft_strjoin(different_path[i], cmd);
		if (access(str, F_OK | R_OK) == 0)
		{
			free_tab(different_path);
			return (str);
		}
		free(str);
		i++;
	}
	free_tab(different_path);
	return (0);
}

char	*find_in_envp(char **env, char *pathvar)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		str = ft_substr(env[i], 0, j);
		if (ft_strncmp(pathvar, str, 4) == 0)
		{
			free(str);
			return (env[i] + j + 1);
		}
		free(str);
		i++;
	}
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*cmd_slash(char *cmd)
{
	char	*str;
	int		i;
	int		j;

	j = 1;
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(cmd) + 2));
	str[0] = '/';
	while (cmd[i])
	{
		str[j] = cmd[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
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
	path = path_creator(command_slash, envp, "PATH");
	if (-1 == execve(path, command, NULL))
	{
		free(command_slash);
		free_tab(command);
		free(path);
		return (0);
	}
	return (1);
}
