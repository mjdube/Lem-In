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
    t_block         *paths[1024];
    t_block         *links[1024];

    map = create_map();
    farm = map;
    if (ft_check_farm(farm))
    {
        ft_putstr("hello -> lem in 1\n");
        ft_scan(&(*links), farm, &start, &end);
        ft_putstr("hello -> lem in 2\n");
        graph = ft_create_graph(links);
    }
    else 
        ft_putendl("Error");

    return (0);
}
