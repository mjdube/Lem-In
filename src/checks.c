#include "lem_in.h"

int         check_room(t_map *graph, t_block *link)
{
    t_map *g;

    g = graph;
    if (!graph || !link)
        return (0);
    while (g)
    {
        if (ft_strcmp(g->roomName, link->nameRoom) == 0)
            return (1);
        g = g->rooms;
    }
    return (0);
}

int         check_links(t_map *graph, t_block *link)
{
    t_map *g;

    g = graph;
    if (!graph || !link)
        return (0);
    while (g)
    {
        if (ft_strcmp(g->roomName, link->nameRoom) == 0)
            return (1);
        g = g->links;
    }
    return (0);
}