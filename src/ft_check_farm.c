#include "lem_in.h"

static int         ft_commands(t_notes *map)
{
    int     i;
    t_notes         *farm;
    
    i = 0;
    farm = map;
    if (!farm)
        return (0);
    while (farm->next != NULL)
    {
        if (ft_search_start_end(farm->note) == 1)
            i++;
        if (ft_search_start_end(farm->note) == 2)
            i++;
        farm = farm->next;
    }
    return (i);
}

static int      ft_ants_map(t_notes *map)
{
    t_notes *farm;

    farm = map;
    if (ft_num_of_ants(farm) > 0)
        return (1);
    return (0);
}

int         ft_check_farm(t_notes *map)
{
    t_notes *farm;
    
    farm = map;
    if (ft_commands(farm) != 2)
        return (0);
    if (!ft_ants_map(farm))
        return (0);
    return (1); 
}