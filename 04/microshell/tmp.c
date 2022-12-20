#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define STD_IN 0
#define STD_OUT 1
#define STD_ERR 2

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2
#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif
typedef struct s_cmd
{
	char 			**argv;
	int				type;
	int				size;
	int				fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	err_fatal()
{
	write(STD_ERR, "error: fatal\n", ft_strlen("error_fatal\n"));
	exit(EXIT_FAILURE);
}

void	err_cd1()
{
	write(STD_ERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
}

void	err_cd2(char *path)
{
	write(STD_ERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STD_ERR, path, ft_strlen(path));
	write(STD_ERR, "\n", ft_strlen("\n"));
}

void	err_execve(char *path)
{
	write(STD_ERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STD_ERR, path, ft_strlen(path));
	write(STD_ERR, "\n", ft_strlen("\n"));
	exit(EXIT_FAILURE);
}

char *ft_strdup(char *str)
{
	int i = 0;
	char	*new;

	if (!str)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		err_fatal();
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	argv_size(char **argv)
{
	int	i = 0;
	while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
		i++;
	return (i);
}

t_cmd *get_last_node(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

void	ft_lstadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd *tmp;

	if (*cmd == NULL)
		*cmd = new;
	else
	{
		tmp = *cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int	get_type(char *argv)
{
	if (argv == NULL)
		return (TYPE_END);
	if (strcmp(argv, "|") == 0)
		return (TYPE_PIPE);
	else if (strcmp(argv, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}

int	parse(t_cmd **cmd, char **argv)
{
	int	size = argv_size(argv);
	t_cmd *new;
	int	i = 0;

	if (!(new = (t_cmd *)malloc(sizeof(t_cmd))))
		err_fatal();
	if (!(new->argv = (char **)malloc(sizeof(char *) * (size + 1))))
		err_fatal();
	while (i < size)
	{
		new->argv[i] = ft_strdup(argv[i]);
		i++;		
	}
	new->argv[i] = NULL;
	new->size = size;
	new->type = get_type(argv[size]);
	ft_lstadd_back(cmd, new);
	if (new->type == TYPE_PIPE || new->type == TYPE_BREAK)
		size++;
	return (size);
}

void	execve_cmd(t_cmd *cmd, char **envp)
{
	int	status;
	pid_t	pid;
	int	pipe_flag;

	pipe_flag = 0;
	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		pipe_flag = 1;
		if (pipe(cmd->fd))
			err_fatal();
	}
	pid = fork();
	if (pid < 0)
		err_fatal();
	if (pid == 0)
	{
		if (cmd->type == TYPE_PIPE && dup2(cmd->fd[STD_OUT], STD_OUT) < 0)
			err_fatal();
		if ((cmd->prev && cmd->prev->type == TYPE_PIPE) && dup2(cmd->prev->fd[STD_IN], STD_IN) < 0)
			err_fatal();
		if (execve(cmd->argv[0], cmd->argv, envp) < 0)
			err_execve(cmd->argv[0]);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_flag == 1)
		{
			close(cmd->fd[STD_OUT]);
			if (cmd->type == TYPE_BREAK || cmd->type == TYPE_END)
				close(cmd->fd[STD_IN]);
		}	
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->fd[STD_IN]);
	}
}

void	execute_cmd(t_cmd *cmd, char **envp)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		if (strcmp(cmd->argv[0], "cd") == 0)
		{
			if (cmd->size < 2)
				err_cd1();
			else if (chdir(cmd->argv[1]))
				err_cd2(cmd->argv[1]);
		}
		else
			execve_cmd(tmp, envp);
		tmp = tmp->next;
	}
}

void free_cmd(t_cmd *cmd)
{
	t_cmd *tmp;
	int i = 0;

	while (cmd)
	{
		tmp = cmd->next;
		i = 0;
		while (cmd->argv[i])
		{
			free(cmd->argv[i]);
			i++;
		}
		free(cmd->argv);
		free(cmd);
		cmd = tmp;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	int	i;

	if (argc < 1)
		return (EXIT_SUCCESS);
	cmd = NULL;
	i = 1;
	while (argv[i])
	{
		if (strcmp(argv[i], ";") == 0)
		{
			i++;
			continue;
		}
		i += parse(&cmd, &argv[i]);
	}
	if (cmd)
		execute_cmd(cmd, envp);
	free_cmd(cmd);
//	while (cmd)
//	{
//		int j = 0;
//		while (cmd->argv[j])
//		{
//			printf ("%s ", cmd->argv[j]);
//			j++;
//		}
//		printf("%d", cmd->type);
//		cmd = cmd->next;
//		printf("\n");
//	}
	if (TEST)
		while (1);	
	return (EXIT_SUCCESS);
}
