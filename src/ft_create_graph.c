#include "lem_in.h"

void		create_room_r(t_map **graph, t_block *link)
{
	t_map 	**temp;
	t_map	*new_link;
	t_map 	*new_room;

	temp = graph;
	new_link = NULL;
	new_room = NULL;
	if ((*temp) == NULL)
	{
		(*temp) = (t_map *)malloc(sizeof(t_map));
		new_link = (t_map *)malloc(sizeof(t_map));

		(*temp)->roomName = link->nameRoom;
		new_link->roomName = link->prev->nameRoom;
		
		(*temp)->links = new_link;
		(*temp)->rooms = NULL;
	}
	else 
	{
		while ((*temp)->rooms != NULL)
		{
			(*temp) = (*temp)->rooms;
		}

		new_room = (t_map *)malloc(sizeof(t_map));
		new_link = (t_map *)malloc(sizeof(t_map));

		new_room->roomName = link->nameRoom;
		new_link->roomName = link->prev->nameRoom;

		new_room->rooms = NULL;
		new_link->links = NULL;

		(*temp)->links = new_link;
		(*temp)->rooms = new_room;
	}
}

void		create_room(t_map **graph, t_block *link)
{
	t_map 	**temp;
	t_map	*new_link;
	t_map 	*new_room;

	temp = graph;
	new_link = NULL;
	new_room = NULL;
	if ((*temp) == NULL)
	{
		(*temp) = (t_map *)malloc(sizeof(t_map));
		new_link = (t_map *)malloc(sizeof(t_map));

		(*temp)->roomName = link->nameRoom;
		new_link->roomName = link->next->nameRoom;

		(*temp)->links = new_link;
		(*temp)->rooms = NULL;
	}
	else 
	{
		while ((*temp)->rooms != NULL)
			(*temp) = (*temp)->rooms;
		new_room = (t_map *)malloc(sizeof(t_map));
		new_link = (t_map *)malloc(sizeof(t_map));

		new_room->roomName = link->nameRoom;
		new_link->roomName = link->next->nameRoom;

		new_room->rooms = NULL;
		new_link->links = NULL;

		(*temp)->links = new_link;
		(*temp)->rooms = new_room;
	}
}

void		found_room_r(t_map **graph, t_block *links)
{
	t_map	**temp;
	t_map	*new_link;

	temp = graph;
	new_link = NULL;
	while ((*temp)->rooms != NULL)
	{
		if (ft_strcmp((*temp)->roomName, links->nameRoom) == 0)
			break ;
		(*temp) = (*temp)->rooms;
	}
	while ((*temp)->links != NULL)
		(*temp) = (*temp)->links;
	new_link = (t_map *)malloc(sizeof(t_map));
	new_link->roomName = links->prev->nameRoom;
	new_link->links = NULL;
	(*temp)->links = new_link;
}

void		found_room(t_map **graph, t_block *links)
{
	t_map	**temp;
	t_map	*new_link;

	temp = graph;
	new_link = NULL;
	while ((*temp))
	{
		if (ft_strcmp((*temp)->roomName, links->nameRoom) == 0)
			break ;
		(*temp) = (*temp)->rooms;
	}
	while ((*temp)->links != NULL)
	{
		(*temp) = (*temp)->links;
	}
	new_link = (t_map *)malloc(sizeof(t_map));
	new_link->roomName = links->next->nameRoom;
	new_link->links = NULL;
	(*temp)->links = new_link;
}

t_map       *ft_create_graph(t_block **links)
{
    int         i;
    t_map       *graph;
    t_block     **link;

    link = links;
    i = 0;
    graph = NULL;
	
    if (links == NULL)
        return (NULL);
	
    while (link[i] != NULL)
    {
		
        if (check_room(graph, link[i]) == 1)
		{
			
			found_room(&graph, link[i]);	
		}			
		else if (check_room(graph, link[i]) == 0)
		{
	
			create_room(&graph, link[i]);
		}
			// create_room(&graph, link[i]);
		ft_putendl(graph->roomName);
		ft_putendl(graph->links->roomName);
		ft_putchar('\n');
		if (check_room(graph, link[i]->next) == 1)
		{
			found_room_r(&graph, link[i]->next);
		}
		else if (check_room(graph, link[i]->next) == 0)
		{
			create_room_r(&graph, link[i]->next);
		}
		ft_putendl(graph->roomName);
		ft_putendl(graph->links->roomName);
		
		ft_putchar('\n');
		i++;
    }
	return (graph);
}