#include "lem_in.h"

void		empty_stack(char **tmp, int i)
{
	int	j;

	j = 0;
	while(tmp[j] && j < i)
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

void		empty_path(t_path *path)
{
	t_path	*current;

	current = NULL;
	while ((current = path) != NULL)
	{
		path = path->next;
		free(current->map);
		free(current);
	}
	free(current);
}

void		empty_rooms(t_rooms *rooms)
{
	t_rooms	*current;

	current = NULL;
	while ((current = rooms) != NULL)
	{
		rooms = rooms->next;
		free(current->data);
		free(current);
	}
	free(rooms);
}

void		empty_links(t_links *links, t_keys *keys)
{
	int	i;

	i = 0;
	while(i < keys->rooms)
	{
		free(links->links[i]);
		i++;
	}
	free(links->links);
	free(links);
}

void		empty(t_links *links, t_rooms *rooms, t_path *visit, t_keys *keys, t_path *path)
{
	free(visit->visits);
	empty_links(links, keys);
	empty_path(path);
	empty_rooms(rooms);
	free(visit);
	free(keys->start);
	free(keys->end);
	free(keys->read);
}
