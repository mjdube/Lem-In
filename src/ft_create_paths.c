#include "lem_in.h"

static int      ft_look_another_path(t_block **links, char *end)
{
    int     i;

    i = 0;
    if (end == NULL)
        return (0);
    while (links[i])
    {
        if (ft_strcmp(links[i]->nameRoom, end) == 0)
        { 
                
        }
        else if (ft_strcmp(links[i]->next->nameRoom, end) == 0)
        {

        }
    }
}

t_block         **ft_create_paths(char *start, char *end, t_block **links)
{
    int         count_path;
    int         i;
    t_block     *pre_path;
    t_block     *paths[1028];

    count_path = 0;
    i = 1;
    // while (i)
    // {
        // ft_path_visits(start, end, ft_links_len(links), &(*links));
        // ft_path_list(start, end, ft_links_len(links), &(*links), pre_path);
        // paths[0] = pre_path;

        // // count_path++;
        // ft_path_visits(start, end, ft_links_len(links), &(*links));
        // ft_path_list(start, end, ft_links_len(links), &(*links), pre_path);
        // paths[1] = pre_path;
    // }
}