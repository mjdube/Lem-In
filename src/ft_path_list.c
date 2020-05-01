#include "lem_in.h"

t_block     *ft_path_list(char *start, char *end, t_block **links)
{
    int     i;

    t_block *node;

    i = 0;
    if (start == NULL || end == NULL || links == NULL)
        return (NULL);
    while (links[i] != NULL)
    {
        if (ft_strcmp(links[i]->nameRoom, start) == 0) 
        {
            if (links[i]->visit == 0)
            {
                start = links[i]->next->nameRoom;
                links[i]->visit = 1;
                links[i]->next->visit = 1;
            }
        }
        else if (ft_strcmp(links[i]->next->nameRoom, start) == 0)
        {
            if (links[i]->next->visit == 0)
            {
                start = links[i]->next->prev->nameRoom;
                links[i]->next->visit = 1;
                links[i]->next->prev->visit = 1;
            }
        }
        i++;
    }
}