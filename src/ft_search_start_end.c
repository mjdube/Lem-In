#include "lem_in.h"

int    ft_start(char *str_start)
{
    if (ft_strcmp("##start", str_start) == 0)
    {
        return (1);
    }
    return (0);
}

int    ft_end(char *str_end)
{
    if (ft_strcmp("##end", str_end) == 0)
    {
        return (1);
    }
    return (0);
}

int     ft_search_start_end(char *s)
{
    if (ft_start(s) == 1)
        return (1);
    else if (ft_end(s) == 1)
        return (2);
    else 
        return (0);
}