/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:15:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/10/02 21:50:17 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include "../../lib/ft_printf/include/ft_printf.h"
#include "../../lib/ft_printf/lib/libft/include/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_command(char **paths, char *cmd)
{
	char	*path_cmd;

	while (*paths)
	{
		path_cmd = ft_strjoin(ft_strjoin(*paths, "/"), cmd);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		paths++;
	}
	return (NULL);
}

char	*get_path(char **envp)
{
	while (!ft_strnstr(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
}

void	first_command(int pipe_fd[], char **argv, char **envp)
{
	int		fd;
	char	*cmd;
	char	**paths;

	close(pipe_fd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror_exit(argv[1]);
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	paths = ft_split(get_path(envp), ':');
	cmd = get_command(paths, ft_split(argv[2], ' ')[0]);
	close(pipe_fd[1]);
	close(fd);
	execve(cmd, ft_split(argv[2], ' '), envp);
}

void	second_command(int pipe_fd[], char **argv, char **envp)
{
	int		fd;
	char	*cmd;
	char	**paths;

	close(pipe_fd[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		ft_perror_exit(argv[4]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	paths = ft_split(get_path(envp), ':');
	cmd = get_command(paths, ft_split(argv[3], ' ')[0]);
	close(pipe_fd[0]);
	close(fd);
	execve(cmd, ft_split(argv[3], ' '), envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid[2];
	int		status;

	if (argc < 5)
		ft_puterr("Invalid number of factors.\n" \
"Usage: ./pipex [file1] [cmd1] [file2]\n");
	if (pipe(pipe_fd) == -1)
		ft_perror_exit("pipe error\n");
	pid[0] = fork();
	if (pid[0] == 0)
		first_command(pipe_fd, argv, envp);
	pid[1] = fork();
	if (pid[1] == 0)
		second_command(pipe_fd, argv, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	return (0);
}
