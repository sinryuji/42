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
	return (NULL);
}

void	exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

int	argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
		i++;
	return (i);
}

int	parse_argv(t_cmd **cmd, char **argv)
{
	int		size;
	t_cmd	*new;

	size = argv_size(argv);
	if (!(new = (t_cmd *)malloc(sizeof(cmd))))
		exit_fatal();
	if (!(new->argv = (char **)malloc(sizeof(char *) * (size + 1))))
		exit_fatal();
	
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
	}
	return (0);
}
