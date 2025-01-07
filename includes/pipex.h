/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:14:00 by asilveir          #+#    #+#             */
/*   Updated: 2025/01/07 11:27:10 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> 
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void	execute_command(char *argv, char **envp);
void	child_proccess(int *fd, char **argv, char **envp);
void	parent_proccess(int *fd, char **argv, char **envp);
void	args_verification(int argc);
void	free_paths(char **paths);
void	free_cmd(char **cmd);
void	exit_if_invalid_path(char **cmd);
int		search_for_path_index(char **envp);
char	*search_valid_path(char *cmd, char **envp);

#endif