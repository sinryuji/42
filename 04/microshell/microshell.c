#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

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
	char **argv;
	int size;
	int	fd[2];
	int type;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

int	ft_strlen(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	err_fatal()
{
	char *msg = "error: fatal\n";

	write(STDERR, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	err_cd_1()
{
	char *msg = "error: cd: bad arguments\n";

	write(STDERR, msg, ft_strlen(msg));
}

void	err_cd_2(char *path)
{
	char *msg = "error: cd: cannot change ";

	write(STDERR, msg, ft_strlen(msg));
	write(STDERR, path, ft_strlen(path));
	write(STDERR, "\n", 1);
}

void	err_execve(char *path)
{
	char *msg = "error: cannot execute ";

	write(STDERR, msg, ft_strlen(msg));
	write(STDERR, path, ft_strlen(path));
	write(STDERR, "\n", 1);
}

char *ft_strdup(char *str)
{
	int i = 0;
	char *new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
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

int get_type(char *argv)
{
	if (argv == NULL)
		return (TYPE_END);
	else if (strcmp(argv, "|") == 0)
		return (TYPE_PIPE);
	else if (strcmp(argv, ";") == 0)
		return (TYPE_BREAK);
	return (TYPE_END);
}

int	parse(t_cmd **cmd, char **argv)
{
	int size = argv_size(argv);
	t_cmd *new;
	int i = 0;

	new = malloc(sizeof(t_cmd));
	if (!new)
		err_fatal();
	new->argv = malloc(sizeof(char *) * (size + 1));
	if (!(new->argv))
		err_fatal();
	while (i < size)
	{
		new->argv[i] = ft_strdup(argv[i]);
		i++;
	}
	new->argv[size] = NULL;
	new->type = get_type(argv[i]);
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	ft_lstadd_back(cmd, new);
	if (new->type == TYPE_PIPE || new->type == TYPE_BREAK)
		size++;
	return (size);
}

void	execve_cmd(t_cmd *cmd, char **envp)
{
	int status;
	pid_t pid;
	int pipe_flag;

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
		if (cmd->type == TYPE_PIPE && dup2(cmd->fd[STDOUT], STDOUT) < 0)
			err_fatal();
		if (cmd->prev && cmd->prev->type == TYPE_PIPE && dup2(cmd->prev->fd[STDIN], STDIN) < 0)
			err_fatal();
		if (execve(cmd->argv[0], cmd->argv, envp) < 0)
			err_execve(cmd->argv[0]);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_flag == 1)
		{
			close(cmd->fd[STDOUT]);
			if (cmd->type == TYPE_BREAK || !cmd->next)
				close(cmd->fd[STDIN]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->fd[STDIN]);
	}
}

void	execute_cmd(t_cmd *cmd, char **envp)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		if (strcmp(tmp->argv[0], "cd") == 0)
		{
			if (tmp->size < 2)
				err_cd_1();
			else if (chdir(tmp->argv[1]))
				err_cd_2(tmp->argv[1]);
		}
		else
			execve_cmd(tmp, envp);
		tmp = tmp->next;
	}
}

void	free_all(t_cmd *cmd)
{
	t_cmd *tmp;
	int	i;

	tmp = cmd;
	while (tmp)
	{
		i = 0;
		while (tmp->argv[i])
		{
			free(tmp->argv[i]);
			i++;
		}
		free(tmp->argv);
		free(tmp);
		tmp = tmp->next;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_cmd *cmd;
	int	i = 1;

	cmd = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);;
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
	free_all(cmd);
	if (TEST)
		while (1);
	return (EXIT_SUCCESS);
}
