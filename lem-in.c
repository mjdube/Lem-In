#include "src/lem_in.h"

int                 main(void)
{
    char            *start;
    char            *end;
    t_notes         *map;
    t_notes         *farm;
    t_map           *graph;
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
            ft_putstr("graph ->> ");
            ft_putendl(graph->roomName);
            ft_create_paths(&(*paths), graph, start, end);
            // while (paths[1])
            // {
            //     ft_putendl(paths[1]->nameRoom);
            //     paths[1] = paths[1]->next;
            // }
            // while (paths[0])
            // {
            //     ft_putendl(paths[0]->nameRoom);
            //     paths[0] = paths[0]->next;
            // }
            // ft_create_paths(&(*paths), graph, start, end);
        }
        else 
            ft_putendl("Error");
    }
    else 
        ft_putendl("Error");
    return (0);
}
