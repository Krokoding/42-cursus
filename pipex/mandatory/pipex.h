/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:20:54 by loris             #+#    #+#             */
/*   Updated: 2023/11/28 21:31:28 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../libft.h"


int	    put_in_pipe(int *fd, char **av, char **envp);
char    *path_creator(char *cmd, char **env, char *pathvar);
int	    put_in_file(int	*fd, char **av, char **envp);
char    *find_in_envp(char **env, char *pathvar);
void    free_tab(char **tab);
char    *cmd_slash(char *cmd);
int	    create_pipe(int *fd, char **av, char **envp);

#endif