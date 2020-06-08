#include "lem_in.h"

int         checks_room(t_notes *map)
{
    int     i;
    t_notes *farm;

    i = 0;
    farm = map;
    while (farm->next != NULL)
    {
        if (ft_strchr(farm->note, ' '))
            i++;
        farm = farm->next;
    }
    return (i);
}

int         check_links(t_notes *map)
{
    int     i;
    t_notes *farm;

    i = 0;
    farm = map;
    while (farm->next != NULL)
    {
        if (ft_strchr(farm->note, '-'))
            i++;
        farm = farm->next;
    }
    return (i);
}