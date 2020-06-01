#include "src/lem_in.h"

int         main()
{
	t_keys  keys;
	t_rooms *rooms;
	t_links	*links;
	t_path	*paths;
	t_path	*path;

	rooms = NULL;
	path = NULL;
	links = NULL;
	paths = NULL;
	ft_begin(&keys); // <- WE ALLOCATE THE IMPORTANT KEYS TO NULL IF IT IS A STRING AND 0 IF IT IS NUMBER
	ft_num_of_ants(&keys); // <- WE READ FROM THE MAP FILE AND CHECK IF IT IS NUMBER AND THEN SET OUR KEY->ANT = ANT NUMBER OF ANTS
    rooms = ft_create_rooms(&keys, rooms); // <- WE READ THE MAP FILE AND CHECK IF THERE ARE ROOMS AND WE COUNT AND COUNT THE NUMBER OF ROOMS = SET KEY->ROOMS = NUMBER OF ROOMS  
    links = ft_create_links(links, rooms, &keys); // <- WE READ THE MAP FILE AND LOOK FOR LINKS AND CREATE LINKS
    ft_check_start_end(&keys); // <- WE CHECK FOR START AND END STRINGS. IF THEY NOT THERE, WE EXIT
	paths = ft_create_path(rooms, links, &keys, paths); // <- WE CREATE DIFFERENT PATHS 
    path = ft_final_path(paths, path, rooms, &keys); // <- WE LOOK FOR THE SHORT PATH AND CREATE THAT PATH
    path = ft_display_1(path, &keys); // <- WE THEN DISPLAY OUR ANTS ON THE STANDARD OUT
	empty(links, rooms, paths, &keys, path); // <- WE THEN WE CLEAR ALL THE LINKED LIST AND IN THE STACK
	return (0);
}