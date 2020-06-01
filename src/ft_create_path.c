#include "lem_in.h"

t_path		*ft_visit_rooms(t_path *visit, int start, int end, t_keys *keys, t_links *links, t_visit *path)
{
	int	i;
	int	j;
	int	s_room;
	int e_room;

	j = 0;
	e_room = 0;
	s_room = -1;
	while (s_room != end)
	{
		i = 0;
		while (i < keys->rooms)
		{
			if (links->links[start][i] == 1 && !ft_dup(path->path, i, keys->rooms))
			{
				visit->visits[++j] = i;
				path->path[++e_room] = i;
				if (i == end)
				{
					visit->visits[j] = i;
					s_room = i;   
					break;
				}
				start = i;
				i = 0;
			}
			i++;
		}
		j = ft_decrem_visit(j);
		start = visit->visits[j];
	}
	return (visit);
}

t_path		*ft_create_path(t_rooms *rooms, t_links *links, t_keys *keys, t_path  *visit)
{
	int	start;
	int	end;
	t_visit *path;

	path = NULL;
	start = ft_is_link(keys->start, rooms);
	end = ft_is_link(keys->end, rooms);
	visit = ft_start_path(visit, keys, start); 
	path = ft_rec_visit(path, keys, start);
	visit = ft_visit_rooms(visit, start, end, keys, links, path);
	free(path->path);
	free(path);
	return (visit);
}