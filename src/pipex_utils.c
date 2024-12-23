/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:13:56 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/17 18:35:29 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*search_valid_path(char *cmd, char **envp)
{
	char		**paths;
	char		*current_path;	
	char		*current_path_and_command;
	int			i;
	int			j;

	j = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i = search_for_path_index(envp);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		free_paths(paths);
	while (paths && paths[j])
	{
		current_path = ft_strjoin(paths[j], "/");
		current_path_and_command = ft_strjoin(current_path, cmd);
		free(current_path);
		if (access(current_path_and_command, F_OK | X_OK) == 0)
			return (current_path_and_command);
		free(current_path_and_command);
		j++;
	}
	free_paths(paths);
	return (NULL);
}

int	search_for_path_index(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break ;
		i++;
	}
	return (i);
}
