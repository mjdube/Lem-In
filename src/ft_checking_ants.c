#include "lem_in.h"

int         ft_checking_ants(t_notes *map)
{
    char    *s;
    int     i;
    
    i = 0;
    s = map->note;
    if (s == NULL)
        return (0);
    if (ft_strlen(s) > 1)
    {
        while (s[i])
        {
            if (ft_isdigit(s[i]))
                i++;
            else 
                return (0);
        }
    }
    else if (ft_strlen(s) == 1) 
    {
        if (ft_isdigit(s[i]))
            return (1);
        else 
            return (0);
    }
    return (1);
}

int            ft_num_of_ants(t_notes *map)
{
    if (ft_checking_ants(map))
        return (ft_atoi(map->note));
    return (0);
}