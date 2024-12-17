/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:32:34 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/17 18:58:42 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char	execute_command(char *argv, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(argv, ' ');
	if (!command || !command[0])
	{
		perror("Invalid command!");
		exit(EXIT_FAILURE);
	}
	path = search_valid_path(command[0], envp);
	if (!path)
	{
		perror("Path error. Invalid command");
		exit(EXIT_FAILURE);
	}
	if (execve(path, command, envp) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

int	child_proccess(int *fd, char **argv, char **envp)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY, 0644);
	if (in_file == -1)
	{
		perror("Error opening input file!");
		exit(127);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(127);
	}
	if (dup2(in_file, STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(126);
	}
	close(in_file);
	close(fd[1]);
	execute_command(argv[2], envp);
}

int	parent_proccess(int *fd, char **argv, char **envp)
{
	int	out_file;

	close(fd[1]);
	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
	{
		perror("Error opening output file!");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	if (dup2(out_file, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	close(out_file);
	close(fd[0]);
	execute_command(argv[3], envp);
}

void	args_verification(int argc)
{
	if (argc < 5)
	{
		perror("Error!\nInvalid number of arguments.");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	fd[2];
	int	id;
	int	bytes_read;

	args_verification(argc);
	if (!search_valid_path(argv[2], envp))
	{
		perror("Error! Command not found");
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("Error in pipe!");
		exit(EXIT_FAILURE);
	}
	id = fork();
	if (id == -1)
	{
		perror("Error:\n Fork failed!");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
		child_proccess(fd, argv, envp);
	else
		parent_proccess(fd, argv, envp);
	return (0);
}
