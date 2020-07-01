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

int         ft_dest_present(t_notes *map)
{
    int     i;
    size_t  len;
    t_notes *farm;

    i = 0;
    farm = map;
    while (farm != NULL)
    {
        len = ft_strlen(farm->note);
        if (len == 7 && !ft_strncmp(farm->note, "##start", 7))
            i++;
        else if (len == 5 && !ft_strncmp(farm->note, "##end", 5))
            i++;
        farm = farm->next;
    }
    return (i);
}