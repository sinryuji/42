#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2

typedef struct	s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
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
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

int	argv_size(char **argv)
{
	int	i = 0;

	while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
		i++;
	return (i);
}

int	parse(t_cmd **cmd, char **argv)
{
	int	size = argv_size(argv);
	t_cmd	*new;
	if (!(new = malloc(sizeof(t_cmd))))
		err_fatal();
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	int		i;
	
	if (argc <= 1)
		return (0);
	i = 0;
	cmd = NULL;
	while (argv[i])
	{
		i += parse(&cmd, &argv[i]);
		i++;
	}

	return (0);
}
