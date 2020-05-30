#include "src/lem_in.h"

int                 main(void)
{
    char            *start;
    char            *end;
    int             ants;
    t_notes         *map;
    t_notes         *farm;
    t_notes         *farm2;
    t_map           *graph;
    t_block         *paths[1024];
    t_block         *links[1024];

    map = create_map();
    farm = map;
    farm2 = map;
    while (farm2->next)
    {
        ft_putendl(farm2->note);
        farm2 = farm2->next;
    }
    if (ft_check_farm(farm))
    {
        if ((ants = ft_num_of_ants(farm)) > 0)
        {
            ft_scan(&(*links), farm, &start, &end);
            graph = ft_create_graph(links);
            ft_create_paths(&(*paths), graph, start, end);
        }
        else 
            ft_putendl("Error");
    }
    else 
        ft_putendl("Error");
    return (0);
}
