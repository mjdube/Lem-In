#include "lem_in.h"

void            ft_path_visits(char *start, char *end, int size, t_block **links)
{
    int         i;

    t_block     *list;

    i = 0;
    list = NULL;
    if (start == NULL ||links == NULL)
        return ;
    while (i < size && ft_strcmp(start, end) != 0)
    {
        if (ft_strcmp(links[i]->nameRoom, start) == 0) 
        {
            if (links[i]->visit_1 == 0)
            {
                // ft_putendl(links[i]->nameRoom);
                // ft_putendl(links[i]->next->nameRoom);
                start = links[i]->next->nameRoom;
                links[i]->visit_1 = 1;
                links[i]->next->visit_1 = 1;
                i = 0;
            }
            else 
                i++;         
        }
        else if (ft_strcmp(links[i]->next->nameRoom, start) == 0)
        {
            if (links[i]->next->visit_1 == 0)
            {
                // ft_putendl(links[i]->next->nameRoom);
                // ft_putendl(links[i]->next->prev->nameRoom);
                start = links[i]->next->prev->nameRoom;
                links[i]->next->visit_1 = 1;
                links[i]->next->prev->visit_1 = 1;
                i = 0;
            }
            else 
                i++;
        }
        else
            i++;
    }
}