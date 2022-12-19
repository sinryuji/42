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

typedef struct s_cmd
{
	char 			**argv;
	int				type;
	int				size;
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
	if (*cmd == NULL)
		*cmd = new;
	else
		get_last_node(*cmd)->next = new;
	if (new->type == TYPE_PIPE || new->type == TYPE_BREAK)
		size++;
	return (size);
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
		i += parse(&cmd, &argv[i]);
	}
	while (cmd)
	{
		int j = 0;
		while (cmd->argv[j])
		{
			printf ("%s ", cmd->argv[j]);
			j++;
		}
		printf("%d", cmd->type);
		cmd = cmd->next;
		printf("\n");
	}
	return (EXIT_SUCCESS);
}
