#include "lem_in.h"

int         ft_find_links(char *s)
{
    char    **links;
    int     i;

    i = 0;
    links = ft_strsplit(s, '-');
    while (links[i])
        i++;
    if (i == 2)
        return (1);
    return (0);
}