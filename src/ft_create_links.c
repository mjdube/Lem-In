#include "lem_in.h"

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
	if (start == -1 || end == -1)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}	
	links->links[start][end] = 1;
	links->links[end][start] = 1;
	return (links);
}

t_links		*ft_create_links(t_links *links, t_rooms *rooms, t_keys *keys, t_notes *map)
{
	int		i;
	t_notes	*farm;

	i = keys->rooms;
	farm = map;
	links = ft_make_links(links, i);
	while (farm)
	{
		if (farm->note[0] != '#' && ft_strchr(farm->note, '-'))
			links = ft_links(rooms, links, farm->note);
		if (farm->next == NULL)
			break ;
		farm = farm->next;
	}
	return (links);
}