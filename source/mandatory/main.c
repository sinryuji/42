/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:15:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/29 12:49:28 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include "../../lib/ft_printf/lib/libft/include/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;
	int		c_num;

	(void)argv;
	c_num = 0;
	if (argc != 5)
		ft_puterr("Invalid number of factors.\n" \
"Usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n");
	pipe(fd);
	pid = fork();
	if (pid != 0)
	{
		c_num++;
		pid = fork();
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		if (c_num == 0)
			close(fd[0]);
		if (c_num == 1)
			close(fd[1]);
	}
	return (0);
}
