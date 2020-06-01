#include "lem_in.h"

int			ft_dup(int *visited, int v, int i)
{
	int	x;

	x = 0;
	while(x < i)
	{
		if (visited[x] == v)
			return (1);
		x++;
	}
	return (0);
}

t_path		*ft_start_path(t_path *visit, t_keys *keys, int start)
{
	if (!(visit = (t_path *)malloc(sizeof(t_path))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (!(visit->visits = (int *)malloc(sizeof(int) * keys->rooms + 1)))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	visit->visits[0] = start;
	return (visit);
}

t_visit		*ft_rec_visit(t_visit *visit, t_keys *keys, int start)
{
	if (!(visit = (t_visit *)malloc(sizeof(t_visit))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (!(visit->path = (int *)malloc(sizeof(int) * keys->rooms + 1)))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	visit->path[0] = start;
	return (visit);
}


int        ft_decrem_visit(int j)
{
	j = j - 1;
	if (j < 0)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	return (j);
}

t_path		*ft_visit_rooms(t_path *visit, int start, int end, t_keys *init, t_links *links, t_visit *path)
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
		while (i < init->rooms)
		{
			if (links->links[start][i] == 1 && !ft_dup(path->path, i, init->rooms))
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

t_path		*ft_create_path(t_rooms *rooms, t_links *links, t_keys *init, t_path  *visit)
{
	int	start;
	int	end;
	t_visit *path;

	path = NULL;
	start = ft_is_link(init->start, rooms);
	end = ft_is_link(init->end, rooms);
	visit = ft_start_path(visit, init, start); 
	path = ft_rec_visit(path, init, start);
	visit = ft_visit_rooms(visit, start, end, init, links, path);
	free(path->path);
	free(path);
	return (visit);
}