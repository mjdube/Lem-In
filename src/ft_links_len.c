#include "lem_in.h"

int         ft_links_len(t_block **links)
{
    int     i;

    i = 0;
    if (links == NULL)
        return (0);
    while (links[i])
        i++;
    return (i);
}