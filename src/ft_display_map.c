#include "lem_in.h"

void        ft_display_map(t_notes *map)
{
    t_notes *farm;

    farm = map;
    while (farm->next != NULL)
    {
        ft_putendl(farm->note);
        farm = farm->next;
    }
    ft_putendl(farm->note);
}