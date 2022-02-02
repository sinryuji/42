#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *elem;
    t_list *current;

    elem = ft_create_elem(data);
    current = *begin_list;
    while (current->next)
	current = current->next;
    currnet->next = elem;
}
