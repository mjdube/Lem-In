#include "src/lem_in.h"



int                 main(int argc, char **argv)
{
    char            *start;
    char            *end;
    int             i;
    int             count_path;
    t_notes         *map;
    t_notes         *farm;
    t_map           *graph;
    t_map           *room;
    t_map           *link;
    t_block         *paths[1024];
    t_block         *links[1024];

    map = create_map();
    farm = map;
    if (ft_check_farm(farm))
    {
        if (ft_num_of_ants(farm) > 0)
        {
            ft_scan(&(*links), farm, &start, &end);

            graph = ft_create_graph(links);
            link  = graph;
            room = graph;
            while (link)
            {
                ft_putendl(link->roomName);
                link = link->links;
            }
            ft_putchar('\n');
            while (room)
            {
                ft_putendl(room->roomName);
                room = room->rooms;
            }
        }
        else 
            ft_putendl("Error");

    }
    else 
        ft_putendl("Error");

    return (0);
}
