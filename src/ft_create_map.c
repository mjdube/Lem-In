#include "lem_in.h"

t_notes	*rest_of_node(t_notes *list, char *str)
{
	t_notes	*node;
	t_notes	*lst;

	lst = list;
	if (!(node = (t_notes *)malloc(sizeof(t_notes))))
    {
        ft_putstr("ERROR\n");
        exit(0);
    }
	node->note = ft_strdup(str);
	node->next = NULL;
	while (lst->next)
		lst = lst->next;
	lst->next = node;
    return (list);
}

t_notes	*head_node(t_notes *map, char *str)
{
	if (str == NULL)
    {
        ft_putstr("ERROR\n");
        exit(0);
    }
	if (map == NULL)
	{
		if (!(map = (t_notes *)malloc(sizeof(t_notes))))
		{
            ft_putstr("ERROR\n");
            exit(0);
        }
		map->note = ft_strdup(str);
		map->next = NULL;
	}
    else
    {
         map = rest_of_node(map, str);
    } 
       
    return(map);
}

t_notes			*ft_create_map(t_notes *map)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
    {
        map = head_node(map, line);
        free(line);
    }
	if (map == NULL)
		return (NULL);
	return (map);
}