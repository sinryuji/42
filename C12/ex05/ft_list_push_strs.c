#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
    t_list *current;
    t_list *tmp;
    int	i;

    i = 1;
    current = ft_create_elem(strs[0]);
    tmp = current;
    while (i < size)
    {
	current = ft_create_elem(strs[i]);
	current->next = tmp;
	tmp = current;
	i++;
    }
    return (current);
}
