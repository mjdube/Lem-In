#include "lem_in.h"

int         ft_rooms_map(t_notes *map)
{
    int     i;
    t_notes *farm;

    i = 0;
    farm = map;
    while (farm)
    {
        if (ft_strchr(farm->note, ' '))
            i++;
        farm = farm->next;
    }
    return (i);
}

int         ft_link_map(t_notes *map)
{
    int     i;
    t_notes *farm;

    i = 0;
    farm = map;
    while (farm)
    {
        if (ft_strchr(farm->note, '-'))
            i++;
        farm = farm->next;
    }
    return (i);
}
