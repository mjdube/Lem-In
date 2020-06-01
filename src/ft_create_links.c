#include "lem_in.h"

t_links		*ft_make_links(t_links *links, int i)
{
	int	x;

	x = 0;
	if (!(links = (t_links *)malloc(sizeof(t_links))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (!(links->links = (int **)malloc(sizeof(int*) * i)))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	while (x < i)
	{
		if (!(links->links[x] = (int *)malloc(sizeof(int) * i)))
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
		x++;
	}
	return (links);
}

int			ft_is_link(char *roomName, t_rooms *rooms)
{
	int		i;
	t_rooms	*temp;

	i = 0;
	temp = rooms;
	while (temp)
	{
		if (!ft_strcmp(roomName, temp->data))
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

t_links		*ft_links(t_rooms *rooms, t_links *links, char *read)
{
	char	**lst;
	int		start;
	int		end;

	lst = ft_strsplit(read, '-');
	start = 0;
	while(lst[start])
		start++;
	if (start != 2)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}	
	start = ft_is_link(lst[0], rooms);
	end = ft_is_link(lst[1], rooms);
	free(lst[0]);
	free(lst[1]);
	free(lst);
	ft_putendl(read);
	if (start == -1 || end == -1)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}	
	links->links[start][end] = 1;
	links->links[end][start] = 1;
	return (links);
}

t_links		*ft_create_links(t_links *links, t_rooms *rooms, t_keys *keys)
{
	int		i;

	i = keys->rooms;
	links = ft_make_links(links, i);
	if (keys->read)
		links = ft_links(rooms, links, keys->read);
	free(keys->read);
	while(get_next_line(0, &keys->read) != 0)
	{
		if (keys->read[0] != '#')
			links = ft_links(rooms, links, keys->read);
		free(keys->read);
	}
	return (links);
}