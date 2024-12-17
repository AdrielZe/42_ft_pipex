#include "./pipex.h"
#include <fcntl.h> // Para usar open()
#include <unistd.h> // Para usar close(), read(), write(), dup2()


// fd[0] is for reading from the pipe.
// fd[1] is for writing to the pipe.

// char	execute_command(char *cmd, char **envp, char *args[])
// {
// 	char *path;

// 	if (!cmd)
// 		return (NULL);

// 	if (execve(ft_strjoin(path, argv[2]), args, env) == -1)
// 	{
// 		perror("execve failed");
// 		return (1);
// 	}

// }

int	child_proccess(int *fd, char **argv)
{
	// int	in_file;
	// char *args[] = {argv[2], argv[1], NULL};
	// char *env[] = {"TEST=ENVIROMENT_VARIABLE", NULL};

	// close(fd[0]);
	// in_file = open(argv[1], O_RDONLY, 0644);
	// if (in_file == -1)
	// {
	// 	perror("Error opening input file!");
	// 	exit(EXIT_FAILURE);
	// }
	// if (dup2(fd[1], STDOUT_FILENO) == -1)
	// {
	// 	perror("dup2 failed");
	// 	exit(EXIT_FAILURE);
	// }
	// if (dup2(in_file, STDIN_FILENO) == -1)
	// {
	// 	perror("dup2 failed");
	// 	exit(EXIT_FAILURE);
	// }
	// close(in_file);
	// close(fd[1]);
	// if (execve(ft_strjoin(PATH, argv[2]), args, env) == -1)
	// {
	// 	perror("execve failed");
	// 	return (1);
	// }
}

// int	parent_proccess(int *fd, char **argv)
// {
// 	int	out_file;
// 	char *args[] = {argv[3], argv[4], NULL};
// 	char *env[] = {"TEST=ENVIROMENT_VARIABLE", NULL};
// 	printf("exece");

// 	close(fd[1]);
// 	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (out_file == -1)
// 	{
// 		perror("Error opening output file!");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (dup2(fd[0], STDIN_FILENO) == -1)
// 	{
// 		perror("dup2 failed");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (dup2(out_file, STDOUT_FILENO) == -1)
// 	{
// 		perror("dup2 failed");
// 		exit(EXIT_FAILURE);
// 	}
// 	close(out_file);
// 	close(fd[0]);
// 	if (execve(ft_strjoin(PATH, argv[3]), args, env) == -1)
// 	{
// 		perror("execve failed");
// 		return (1);
// 	}

// }
void	args_verification(int argc)
{
	if(argc < )
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
	if(!search_valid_path(argv[2], envp))
		perror("Error! Command not found");
	// if (pipe(fd) == -1)
	// {
	// 	perror("Error in pipe!");
	// 	return (1);
	// }
	// id = fork();
	// if (id == -1)
	// {
	// 	perror("Error:\n Fork failed!");
	// 	return (1);
	// }
	// if (id == 0)
	// {
	// 	child_proccess(fd, argv);
	// }
	// else 
	// {
       //  	wait(0);
	// 	// parent_proccess(fd,argv, buffer);
	// }
	
	return (0);
}
