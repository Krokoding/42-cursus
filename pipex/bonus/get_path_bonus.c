/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:09:58 by loris             #+#    #+#             */
/*   Updated: 2023/11/28 20:06:33 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char *path_creator(char *cmd, char **env, char *pathvar)
{
    char    *allpath;
	char    **different_path;
    int i;
    char *str;
    
    allpath = find_in_envp(env, pathvar);
    i = 0;
    different_path = ft_split(allpath, ':');
    while(different_path[i])
    {
        str = ft_strjoin(different_path[i], cmd);
        if (access(str, F_OK | X_OK) == 0)
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

char *find_in_envp(char **env, char *pathvar)
{
    int     i;
    int     j;
    char    *str;
    
    i = 0;
    while(env[i])
    {
        j = 0;
        while(env[i][j] && env[i][j] != '=')
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

void    free_tab(char **tab)
{
    int i;
    
    i = 0;
    while(tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char    *cmd_slash(char *cmd)
{
    char *str;
    int i;
    int j;

    j = 1;
    i = 0;
    str = malloc(sizeof(char) * (ft_strlen(cmd) + 2));
    str[0] = '/';
    while(cmd[i])
    {
        str[j] = cmd[i];
        j++;
        i++;
    }
    str[j] = '\0';
    return (str);
}