#include "src/lem_in.h"

int                 main(void)
{
    char            *start;
    char            *end;
    int             ants;
    t_ants          *head;
    t_notes         *map;
    t_notes         *farm;
    t_map           *graph;
    t_block         *paths[1024];
    t_block         *links[1024];

    map = create_map();
    farm = map;

    /* ft_check_farm 

        checks number of ants
        check startt and end commands
        checks the int max

        // needs to be added is 
        --- check rooms
        --- check solution
    */
    if (ft_check_farm(farm))
    {
        if ((ants = ft_num_of_ants(farm)) > 0)
        {
            head = ft_ants(ants);
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
