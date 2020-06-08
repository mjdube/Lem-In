#include "src/lem_in.h"

int         main()
{
	t_keys 	keys;
	t_rooms	*rooms;
	t_notes	*map;
	t_links	*links;
	t_path	*paths;
	t_path	*path;
	
	rooms = NULL;
	map = NULL;
	path = NULL;
	links = NULL;
	paths = NULL;
	
	ft_begin(&keys); 
	map = ft_create_map(map); 
	if (map != NULL)
	{
		ft_num_of_ants(&keys, map); 
    	if (checks_room(map) > 0 && check_links(map) > 0)
		{
			rooms = ft_create_rooms(&keys, rooms, map);
			links = ft_create_links(links, rooms, &keys, map); 
		}
		else 
		{
			empty_map(map);
			ft_putstr("ERROR\n");
			exit(0);
		}
		ft_check_start_end(&keys); 
		paths = ft_create_path(rooms, links, &keys, paths); 
    	path = ft_final_path(paths, path, rooms, &keys); 
		ft_display_map(map); 
		path = ft_display_1(path, &keys); 
		empty(links, rooms, paths, &keys, path, map); 
	}
	else 
	{
		empty_map(map);
		ft_putendl("ERROR");
		exit(0);
	}
	return (0);
}