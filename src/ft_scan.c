#include "lem_in.h"

/*ft_scan

    basically it looks for the commands
    looks for links
    at the end it create links
*/

void            ft_scan(t_block **links, t_notes *map, char **s, char **e)
{
    int         count_links;
    char        **start;
    char        **end;
    t_notes     *farm;

    farm = map;
    count_links = 0;
    while (farm)
    {
        if (ft_find_links(farm->note))
        {
            links[count_links] = ft_create_links(farm->note);
            count_links++;
            farm = farm->next;
        }
        else if (ft_search_start_end(farm->note) == 1)
        {
            start = ft_strsplit(farm->next->note, ' ');
            *s = start[0]; 
            farm = farm->next;
        }
        else if (ft_search_start_end(farm->note) == 2)
        {
            end = ft_strsplit(farm->next->note, ' ');
            *e = end[0];
            farm = farm->next;
        }
        else 
            farm = farm->next;
    }
}