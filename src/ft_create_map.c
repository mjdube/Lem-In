#include "lem_in.h"

void	empty_stack(t_block **lst)
{
	t_block *temp;

	while ((*lst)->next != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	// free(temp);
}

static void	rest_of_node(t_notes **list, char *str)
{
	t_notes	*node;
	t_notes	*lst;

	lst = *list;
	if (!(node = (t_notes *)malloc(sizeof(t_notes))))
		return ;
	node->note = str;
	node->next = NULL;
	node->prev = NULL;
	while (lst->next)
		lst = lst->next;
	lst->next = node;
	node->prev = lst;
	node = NULL;
}

static void	head_node(t_notes **list, char *str)
{
	int		i;

	i = 0;
	if (!*list)
	{
		if (!(*list = (t_notes *)malloc(sizeof(t_notes))) || !str)
			return ;
		(*list)->note = str;
		(*list)->next = NULL;
		(*list)->prev = NULL;
	}
	rest_of_node(list, str);
}

t_notes			*create_map(void)
{
	t_notes		*list;
	int			i;
	int			check;
	char		*line;

	i = 0;
	list = NULL;
	while (get_next_line(0, &line) > 0)
	{
		head_node(&list, line);
	}
	return (list);
}