/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:32:34 by asilveir          #+#    #+#             */
/*   Updated: 2025/01/07 11:36:06 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	execute_command(char *argv, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(argv, ' ');
	if (!command || !command[0])
	{
		perror("command not found: ");
		exit(EXIT_FAILURE);
	}
	path = search_valid_path(command[0], envp);
	if (!path)
		exit_if_invalid_path(&command[0]);
	if (execve(path, command, envp) == -1)
	{
		perror("execve failed.");
		exit(127);
	}
}

void	child_proccess(int *fd, char **argv, char **envp)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY, 0644);
	if (in_file == -1)
	{
		perror("error opening input file");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 for fd[1] failed.");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	if (dup2(in_file, STDIN_FILENO) == -1)
	{
		perror("dup2 for in file failed.");
		exit(EXIT_FAILURE);
	}
	close(in_file);
	close(fd[0]);
	execute_command(argv[2], envp);
}

void	parent_proccess(int *fd, char **argv, char **envp)
{
	int	out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
	{
		perror("error opening output file.");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 for fd[0] failed.");
		exit(127);
	}
	close(fd[0]);
	if (dup2(out_file, STDOUT_FILENO) == -1)
	{
		perror("dup2 for fd[1] failed.");
		exit(127);
	}
	close(out_file);
	close(fd[1]);
	execute_command(argv[3], envp);
}

void	args_verification(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("error!\ninvalid number of arguments.", 1);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	fd[2];
	int	id;

	args_verification(argc);
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	id = fork();
	if (id == -1)
	{
		perror("error:\n Fork failed.");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
		child_proccess(fd, argv, envp);
	else
	{
		waitpid(id, NULL, WNOHANG);
		parent_proccess(fd, argv, envp);
	}
	return (0);
}
