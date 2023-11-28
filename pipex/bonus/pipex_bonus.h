/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:09:38 by loris             #+#    #+#             */
/*   Updated: 2023/11/28 21:31:41 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../libft.h"

char    *path_creator(char *cmd, char **env, char *pathvar);
char    *find_in_envp(char **env, char *pathvar);
void    free_tab(char **tab);
char    *cmd_slash(char *cmd);
int     pipe_creator(char **env, char *av);
int 	open_here_doc(char **av);
int 	here_doc(char **av, int *fd);

#endif