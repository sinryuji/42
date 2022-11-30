#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

typedef struct s_cmd
{
	char			**argv;
	int				size;
	int				type;
	int				fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

int	ft_strlen(char *str)
{
	int	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

void	exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

void	err_cd_argc(void)
{
	write(STDERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
}

void	err_cd_fail(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
}

void	exit_execve(char *str)
{
	write(STDERR, "error: cannot execute " , ft_strlen( "error: cannot execute "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
}

int	argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
		i++;
	return (i);
}

int	get_type(char *argv)
{
	if (!argv)
		return (TYPE_END);
	if (strcmp(argv, "|") == 0)
		return (TYPE_PIPE);
	if (strcmp(argv, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}

void	ft_lstadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd *tmp;

	if (!(*cmd))
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

#include <stdio.h>
int	parse_argv(t_cmd **cmd, char **argv)
{
	int		size;
	int		i;
	t_cmd	*new;

	size = argv_size(argv);
	if (!(new = (t_cmd *)malloc(sizeof(t_cmd))))
		exit_fatal();
	if (!(new->argv = (char **)malloc(sizeof(char *) * (size + 1))))
		exit_fatal();
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	i = 0;
	while (i < size)
	{
		new->argv[i] = ft_strdup(argv[i]);
		i++;
	}
    new->argv[i] = NULL;
	new->type = get_type(argv[size]);
	ft_lstadd_back(cmd, new);
	if (new->type == TYPE_END)
		size--;
	return (size);
}

void	execute_cmd(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	int		status;
	int		pipe_flag;

	pipe_flag = 0;
	if (cmd->type == TYPE_PIPE || cmd->prev && cmd->prev->type == TYPE_PIPE)
	{
		pipe_flag = 1;
		if (pipe(cmd->fd) == -1)
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		if (cmd->type == TYPE_PIPE && dup2(cmd->fd[STDOUT], STDOUT) < 0)
			exit_fatal();
		if (cmd->prev && cmd->prev->type == TYPE_PIPE && dup2(cmd->prev->fd[STDIN], STDIN) < 0)
			exit_fatal();
		if ((execve(cmd->argv[0], cmd->argv, envp)) < 0)
			exit_execve(cmd->argv[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_flag)
		{
			close(cmd->fd[STDOUT]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->fd[STDIN]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->fd[STDIN]);
	}
}

void	execute(t_cmd *cmd, char **envp)
{
	while (cmd)
	{
		if (strcmp(cmd->argv[0], "cd") == 0)
		{
			if (cmd->size != 2)
				err_cd_argc();
			else if (chdir(cmd->argv[1]))
				err_cd_fail(cmd->argv[1]);
		}
		else
			execute_cmd(cmd, envp);
		cmd = cmd->next;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	int		i;

	i = 1;
	cmd = NULL;
	if (argc > 1)
	{
		while (argv[i])
		{
			i += parse_argv(&cmd, &argv[i]);
			i++;
		}
		execute(cmd, envp);
//		while (cmd)
//		{
//			int	j = 0;
//			while (cmd->argv[j])
//			{
//				printf("%s ", cmd->argv[j]);
//				j++;
//			}
//			printf("\n");
//			cmd = cmd->next;
//		}
	}
	return (0);
}
